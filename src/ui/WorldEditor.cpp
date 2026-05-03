// WorldEditor.cpp
// ImGui "World Editor" panel implementation.
// Lets you click on the ground to place prefab instances, save them to cell JSON,
// and reload them on the next run.

#include "WorldEditor.hpp"
#include "../assets/AssetRegistry.hpp"
#include "../world/WorldGrid.hpp"
#include "../game/Forest.hpp"
#include "../game/CameraController.hpp"
#include "../rendering/d3d11/D3D11Renderer.hpp"
#include "../logger/Logger.hpp"

// ImGui (vendored)
#include "../../third_party/imgui/imgui.h"

// Physics raycast
#include "tp_physics.hpp"

#include <cmath>
#include <sstream>

// ---------------------------------------------------------------------------
// SetReferences
// ---------------------------------------------------------------------------
void WorldEditor::SetReferences(AssetRegistry* registry, WorldGrid* grid, Forest* forest)
{
    m_registry = registry;
    m_grid     = grid;
    m_forest   = forest;
    RefreshPrefabList();
}

// ---------------------------------------------------------------------------
// RefreshPrefabList
// ---------------------------------------------------------------------------
void WorldEditor::RefreshPrefabList()
{
    m_prefabIds.clear();
    if (!m_registry) return;

    m_prefabIds = m_registry->GetIdsByPrefix("prefabs.");

    // Fallback: always show at least one entry so the editor isn't empty.
    if (m_prefabIds.empty())
        m_prefabIds.push_back("prefabs.tree");

    // Clamp selection index.
    if (m_selectedPrefabIdx >= static_cast<int>(m_prefabIds.size()))
        m_selectedPrefabIdx = 0;
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
    ImGui::Checkbox("Placement Mode", &m_placementMode);
    if (m_placementMode)
    {
        ImGui::SameLine();
        ImGui::TextColored(ImVec4(0.2f, 1.0f, 0.2f, 1.0f), "(ACTIVE)");
    }

    ImGui::Separator();

    // --- Prefab selection ---
    ImGui::Text("Prefab:");
    if (!m_prefabIds.empty())
    {
        if (ImGui::BeginListBox("##prefabs", ImVec2(-1.0f, 80.0f)))
        {
            for (int i = 0; i < static_cast<int>(m_prefabIds.size()); ++i)
            {
                bool selected = (i == m_selectedPrefabIdx);
                if (ImGui::Selectable(m_prefabIds[i].c_str(), selected))
                    m_selectedPrefabIdx = i;
                if (selected) ImGui::SetItemDefaultFocus();
            }
            ImGui::EndListBox();
        }
    }
    else
    {
        ImGui::TextDisabled("(no prefabs registered)");
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
            // Repopulate forest without the authored instances.
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
    if (m_prefabIds.empty()) return false;

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
        if (fabsf(dy) > 1e-6f)
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
    const std::string& prefabId = m_prefabIds[m_selectedPrefabIdx];
    CellInstance inst;
    inst.prefab = prefabId;
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

    // Spawn visually in the forest (same representation as procedural trees for now).
    m_forest->AddInstance(renderer, hitX, hitY, hitZ, inst.scale);

    std::ostringstream ss;
    ss << "WorldEditor: placed '" << prefabId
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
        m_forest->AddInstance(renderer, inst.x, inst.y, inst.z, inst.scale);

    std::ostringstream ss;
    ss << "WorldEditor: spawned " << cell->instances.size()
       << " authored instance(s) from cell (" << cx << "," << cz << ")";
    LOG_INFO(ss.str());
}
