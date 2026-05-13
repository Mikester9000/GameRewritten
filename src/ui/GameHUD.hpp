#pragma once

#include "../game/actors/PlayerStats.hpp"

struct ImGuiIO;

class GameHUD
{
public:
    // totalTime is used to drive the low-HP pulse animation (pass a running
    // game-time counter, e.g. the same one used for the clear-color pulse).
    void Draw(const PlayerStats& stats, const ImGuiIO& io, float totalTime);
};
