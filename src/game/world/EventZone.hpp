#pragma once

#include <DirectXMath.h>
#include <functional>
#include <vector>

struct EventZone
{
    DirectX::XMFLOAT3 pos{};
    DirectX::XMFLOAT3 halfExtents{};
    int eventID = 0;
    bool oneShot = true;
    bool triggered = false;
};

class EventZoneRegistry
{
public:
    void AddZone(const EventZone& zone);
    void Clear();
    void Update(const DirectX::XMFLOAT3& playerPos, const std::function<void(int)>& onEnter);

private:
    std::vector<EventZone> m_zones;
};
