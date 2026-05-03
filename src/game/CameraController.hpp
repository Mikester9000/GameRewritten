#pragma once
// CameraController.hpp
// Owns all camera + player movement state, isolating it from Main.cpp.
//
// Usage:
//   CameraController cam;
//   cam.Init(0.f, 0.f, -3.f, 0.f, -0.5f);
//   cam.SetCenterPoint(centerPoint);
//   // each frame:
//   cam.Update(dt, paused, firstFrame, renderer);
//   // for mouse picking:
//   cam.ScreenPointToRay(mx, my, vpW, vpH, ox, oy, oz, dx, dy, dz);

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

class D3D11Renderer; // forward declaration

class CameraController
{
public:
    // --- Tweakable parameters (public for easy access) ---
    float cameraDistance = 4.0f;  // distance behind player
    float cameraHeight   = 2.0f;  // camera height above player
    float eyeOffset      = 1.0f;  // how high the player eye sits above ground

    // Set initial state. Call once before the game loop.
    void Init(float startX, float startY, float startZ,
              float startYaw, float startPitch);

    // Set the screen centre point used for mouse-delta look.
    void SetCenterPoint(POINT center);

    // Advance camera + player movement by one frame.
    // paused       = true when pause menu or editor mode is active (skips input + movement).
    // inOutFirstFrame = true on the very first tick; suppresses the large initial delta.
    void Update(float dt, bool paused, bool& inOutFirstFrame, D3D11Renderer& renderer);

    // Build a world-space picking ray from a screen-space mouse position.
    // mouseX/mouseY = client-space pixel coordinates (top-left = 0,0).
    // vpW/vpH       = viewport width/height in pixels (== render resolution).
    // Writes to outOrigin* and outDir* (outDir is normalised).
    void ScreenPointToRay(float mouseX, float mouseY,
                          float vpW,    float vpH,
                          float& outOriginX, float& outOriginY, float& outOriginZ,
                          float& outDirX,    float& outDirY,    float& outDirZ) const;

    // --- Accessors ---
    float GetPlayerX() const { return m_playerX; }
    float GetPlayerY() const { return m_playerY; }
    float GetPlayerZ() const { return m_playerZ; }
    float GetYaw()     const { return m_yaw; }
    float GetPitch()   const { return m_pitch; }
    // Camera follow position (behind + above the player).
    float GetCamX()    const { return m_camX; }
    float GetCamY()    const { return m_camY; }
    float GetCamZ()    const { return m_camZ; }

private:
    float m_playerX = 0.0f, m_playerY = 0.0f, m_playerZ = -3.0f;
    float m_yaw = 0.0f, m_pitch = 0.0f;
    float m_camX = 0.0f, m_camY = 0.0f, m_camZ = 0.0f;
    float m_velocityY  = 0.0f;
    bool  m_isGrounded = true;
    POINT m_centerPoint = {};

    // Recompute m_camX/Y/Z from player pos + yaw.
    void ComputeCamFromPlayer();
};
