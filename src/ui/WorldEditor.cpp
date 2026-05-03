// WorldEditor.cpp
// ImGui "World Editor" panel implementation.
// Lets you click on the ground to place prefab instances, save them to cell JSON,
// and reload them on the next run.

#include "WorldEditor.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../world/WorldGrid.hpp"
#include "../game/Forest.hpp"
#include "../game/PrefabLibrary.hpp"
#include "../game/PrimitiveRenderer.hpp"
#include "../game/CameraController.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../logger/Logger.hpp"

// ImGui (vendored)
#include "../../third_party/imgui/imgui.h"

// Physics raycast
#include "tp_physics.hpp"

#include <cmath>
#include <algorithm>
#include <sstream>

// ---------------------------------------------------------------------------
// SetReferences
// ---------------------------------------------------------------------------
void WorldEditor::SetReferences(AssetRegistry* registry, WorldGrid* grid, Forest* forest,
                                 PrefabLibrary* prefabLib, PrimitiveRenderer* primRenderer)
{
    m_registry     = registry;
    m_grid         = grid;
    m_forest       = forest;
    m_prefabLib    = prefabLib;
    m_primRenderer = primRenderer;
    RefreshPrefabList();
}

// ---------------------------------------------------------------------------
// RefreshPrefabList
// ---------------------------------------------------------------------------
void WorldEditor::RefreshPrefabList()
{
    // Remember the current selection so it survives a reload.
    std::string prevSelected = m_selectedPrefabId;

    m_prefabIds.clear();
    if (!m_registry) return;

    m_prefabIds = m_registry->GetIdsByPrefix("prefabs.");
    // Sort so the list is deterministic across runs/reloads regardless of
    // unordered_map iteration order.
    std::sort(m_prefabIds.begin(), m_prefabIds.end());

    // Do NOT inject a fallback entry when the list is empty — placing an instance
    // that references an unregistered ID would corrupt the cell file.

    // Restore previous selection by ID; fall back to the first entry if not found.
    m_selectedPrefabId.clear();
    if (!m_prefabIds.empty())
    {
        auto it = std::find(m_prefabIds.begin(), m_prefabIds.end(), prevSelected);
        m_selectedPrefabId = (it != m_prefabIds.end()) ? *it : m_prefabIds[0];
    }
}

// ---------------------------------------------------------------------------
// DrawPanel
// ---------------------------------------------------------------------------
void WorldEditor::DrawPanel(int playerCX, int playerCZ, D3D11Renderer& renderer)
{
    // Count instances in the active cell.
    int instanceCount = 0;
    if (m_grid)
    {
        const WorldCell* cell = m_grid->FindCell(playerCX, playerCZ);
        if (cell) instanceCount = static_cast<int>(cell->instances.size());
    }

    ImGui::SetNextWindowSize(ImVec2(280.0f, 0.0f), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(10.0f, 160.0f), ImGuiCond_Once);

    if (!ImGui::Begin("World Editor"))
    {
        ImGui::End();
        return;
    }

    // --- Placement mode toggle ---
    // Disable the checkbox (and force mode off) when no prefabs are registered,
    // so clicks can't write instances referencing non-existent asset IDs.
    if (m_prefabIds.empty())
    {
        m_placementMode = false;
        ImGui::BeginDisabled();
    }
    ImGui::Checkbox("Placement Mode", &m_placementMode);
    if (m_prefabIds.empty())
        ImGui::EndDisabled();
    if (m_placementMode)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "(ACTIVE)");
    }

    ImGui::Separator();

    // --- Prefab selection ---
    ImGui::Text("Prefab:");
    // Warning color used when the prefab list is empty.
    static constexpr ImVec4 WARNING_COLOR = ImVec4(1.0f, 0.4f, 0.4f, 1.0f);
    if (!m_prefabIds.empty())
    {
        if (ImGui::BeginListBox("##prefabs", ImVec2(-1.0f, 80.0f)))
        {
            for (const auto& id : m_prefabIds)
            {
                bool selected = (id == m_selectedPrefabId);
                if (ImGui::Selectable(id.c_str(), selected))
                    m_selectedPrefabId = id;
                if (selected) ImGui::SetItemDefaultFocus();
            }
            ImGui::EndListBox();
        }
    }
    else
    {
        ImGui::TextColored(WARNING_COLOR,
            "No prefabs registered.");
        ImGui::TextDisabled("Add 'prefabs.*' entries to");
        ImGui::TextDisabled("Content/AssetRegistry.json");
        ImGui::TextDisabled("then press F5 to reload.");
    }

    ImGui::Separator();

    // --- Cell info ---
    ImGui::Text("Active cell: (%d, %d)", playerCX, playerCZ);
    ImGui::Text("Instances: %d", instanceCount);

    ImGui::Separator();

    // --- Action buttons ---
    if (ImGui::Button("Save Cell") && m_grid)
    {
        if (m_grid->SaveCell(playerCX, playerCZ))
            LOG_INFO("WorldEditor: cell saved.");
        else
            LOG_WARN("WorldEditor: cell save failed.");
    }

    ImGui::SameLine();

    if (ImGui::Button("Clear Instances") && m_grid && m_forest)
    {
        WorldCell* cell = m_grid->FindCell(playerCX, playerCZ);
        if (cell)
        {
            cell->instances.clear();
            // Clear authored prefab parts from the primitive renderer.
            if (m_primRenderer) m_primRenderer->ClearInstances();
            // Repopulate procedural forest trees without the authored instances.
            if (cell->forestEnabled)
                m_forest->Populate(renderer, cell->forestTreeCount,
                                   cell->forestRadius,
                                   cell->CenterX(), cell->CenterZ());
            else
                m_forest->ClearInstances();
            LOG_INFO("WorldEditor: instances cleared.");
        }
    }

    ImGui::Separator();
    ImGui::TextDisabled("[LMB] click to place when Placement Mode is on");
    ImGui::TextDisabled("[F5] to reload world + registry");

    ImGui::End();
}

// ---------------------------------------------------------------------------
// HandlePlacement
// ---------------------------------------------------------------------------
bool WorldEditor::HandlePlacement(POINT screenPos,
                                   float vpW, float vpH,
                                   const CameraController& cam,
                                   D3D11Renderer& renderer,
                                   int activeCX, int activeCZ)
{
    if (!m_placementMode || !m_grid || !m_forest) return false;
    if (m_prefabIds.empty() || m_selectedPrefabId.empty()) return false;

    // Build picking ray from screen position.
    float ox, oy, oz, dx, dy, dz;
    cam.ScreenPointToRay(static_cast<float>(screenPos.x),
                          static_cast<float>(screenPos.y),
                          vpW, vpH,
                          ox, oy, oz, dx, dy, dz);

    // --- Try Jolt raycast against physics bodies (static ground) ---
    float hitX = 0.0f, hitY = 0.0f, hitZ = 0.0f;
    bool  placed = false;

    auto joltHit = tp::Physics::CastRay(ox, oy, oz, dx, dy, dz, 2000.0f);
    if (joltHit.hit)
    {
        hitX = joltHit.x;
        hitY = joltHit.y;
        hitZ = joltHit.z;
        placed = true;
    }
    else
    {
        // Fallback: intersect ray with the Y=0 ground plane (or terrain baseline).
        // Ray: P = origin + t * dir.  At Y=0: t = -oy / dy.
        static const float MIN_RAY_DIR_EPSILON = 1e-6f;
        if (fabsf(dy) > MIN_RAY_DIR_EPSILON)
        {
            float t = -oy / dy;
            if (t > 0.0f)
            {
                hitX   = ox + dx * t;
                hitY   = 0.0f;
                hitZ   = oz + dz * t;
                placed = true;
            }
        }
    }

    if (!placed) return false;

    // Snap Y to terrain surface so the instance sits on the ground.
    if (renderer.IsTerrainAvailable())
        hitY = renderer.SampleTerrainHeight(hitX, hitZ);

    // Create the instance record.
    CellInstance inst;
    inst.prefab = m_selectedPrefabId;
    inst.x      = hitX;
    inst.y      = hitY;
    inst.z      = hitZ;
    inst.yaw    = 0.0f;
    inst.scale  = 1.0f;

    // Add to cell.
    WorldCell* cell = m_grid->FindCell(activeCX, activeCZ);
    if (!cell)
    {
        LOG_WARN("WorldEditor: active cell not found, cannot store instance.");
        return false;
    }
    cell->instances.push_back(inst);

    // Spawn visually using the primitive renderer (preferred) or fall back to
    // the legacy forest renderer if no PrefabLibrary is available.
    if (m_primRenderer && m_prefabLib)
    {
        const PrimitivePrefab* prefab = m_prefabLib->GetPrefab(m_selectedPrefabId);
        if (prefab)
            m_primRenderer->AddInstance(*prefab, hitX, hitY, hitZ, inst.yaw, inst.scale);
        else
            m_forest->AddInstance(renderer, hitX, hitY, hitZ, inst.scale); // fallback
    }
    else
    {
        m_forest->AddInstance(renderer, hitX, hitY, hitZ, inst.scale);
    }

    std::ostringstream ss;
    ss << "WorldEditor: placed '" << m_selectedPrefabId
       << "' at (" << hitX << ", " << hitY << ", " << hitZ << ")";
    LOG_INFO(ss.str());
    return true;
}

// ---------------------------------------------------------------------------
// SpawnCellInstances
// ---------------------------------------------------------------------------
void WorldEditor::SpawnCellInstances(int cx, int cz, D3D11Renderer& renderer)
{
    if (!m_grid || !m_forest) return;

    const WorldCell* cell = m_grid->FindCell(cx, cz);
    if (!cell || cell->instances.empty()) return;

    for (const auto& inst : cell->instances)
    {
        if (m_primRenderer && m_prefabLib)
        {
            const PrimitivePrefab* prefab = m_prefabLib->GetPrefab(inst.prefab);
            if (prefab)
            {
                m_primRenderer->AddInstance(*prefab, inst.x, inst.y, inst.z, inst.yaw, inst.scale);
                continue;
            }
        }
        // Fallback: use legacy forest cube for prefabs not in the library.
        m_forest->AddInstance(renderer, inst.x, inst.y, inst.z, inst.scale);
    }

    std::ostringstream ss;
    ss << "WorldEditor: spawned " << cell->instances.size()
       << " authored instance(s) from cell (" << cx << "," << cz << ")";
    LOG_INFO(ss.str());
}
