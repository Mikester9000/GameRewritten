#pragma once
// WorldMap.hpp
// Full-screen world map overlay with continent-level zoom and player marker.
// Wraps the MapScreen for zoomed-in region view.

class WorldMap
{
public:
    // Continent zoom level: 0 = zoomed out (whole world), 1 = region.
    void SetZoom(int level) { m_zoom = level; }
    int  GetZoom()  const   { return m_zoom; }

    void Open()  { m_open = true; }
    void Close() { m_open = false; }
    bool IsOpen() const { return m_open; }

    // Draw the world map overlay inside an active ImGui frame.
    // playerX/Z are world-space coordinates; vpW/H are viewport dimensions.
    void Draw(float playerX, float playerZ, float vpW, float vpH);

private:
    bool m_open = false;
    int  m_zoom = 0;        // 0 = continent, 1 = region

    void DrawContinent(float playerX, float playerZ, float vpW, float vpH);
    void DrawRegion   (float playerX, float playerZ, float vpW, float vpH);
};
