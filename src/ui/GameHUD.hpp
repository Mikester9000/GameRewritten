#pragma once

#include "../game/actors/PlayerStats.hpp"

struct ImGuiIO;

class GameHUD
{
public:
    void Draw(const PlayerStats& stats, const ImGuiIO& io);
};
