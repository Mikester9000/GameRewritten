#pragma once
// ChestActor.hpp
// A world-space treasure chest that opens once and drops its loot list
// when the player presses E while in range.

#include <string>
#include <vector>

class PrimitiveRenderer;
struct NotificationSystem;

struct LootEntry
{
    std::string itemName;
    int         quantity = 1;
};

class ChestActor
{
public:
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;

    float              interactRadius = 2.5f;
    bool               opened        = false;
    std::vector<LootEntry> loot;

    void Init(float startX, float startZ,
              std::vector<LootEntry> lootItems,
              float radius = 2.5f);

    // Returns true the frame the chest is opened (use to emit notifications).
    // interactPressed must be a one-shot edge-detected value.
    bool Update(float playerX, float playerZ, bool interactPressed);

    void SubmitVisual(PrimitiveRenderer& pr) const;
};
