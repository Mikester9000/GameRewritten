#pragma once
#include <windows.h>
#include <d3d11.h>
#include <DirectXMath.h>
#include <vector>
#include <string>

// A simple class for setting up and drawing with Direct3D 11.
class D3D11Renderer
{
public:
    // Parameters that drive biome-specific terrain generation.
    struct TerrainParams
    {
        std::string biome      = "grassland"; // grassland | desert | rocky | snow
        int         seed       = 12345;
        float       cellOriginX = 0.0f;  // world-space X of cell bottom-left corner
        float       cellOriginZ = 0.0f;  // world-space Z of cell bottom-left corner
        float       cellWorldSize = 400.0f; // cell side length in world units
        float       heightScale = 8.0f;
        float       noiseFreq  = 0.08f;
        float       noiseFreq2 = 0.03f;
    };
    D3D11Renderer();
    bool Initialize(HWND windowHandle, int width, int height);
    void Shutdown();
    void ClearScreen(float red, float green, float blue, float alpha);
    void PresentFrame();
    void DrawRotatingTriangle(float deltaTime);
	void DrawSky();
    void SetCameraPosition(float x, float y, float z);
    void SetCameraRotation(float yaw, float pitch);
    void GetCameraPosition(float& x, float& y, float& z) const;
    void GetCameraRotation(float& yaw, float& pitch) const;
    void DrawGroundPlane();
    void DrawTerrainPatch();
    // Rebuild the terrain mesh from biome/seed parameters (called on cell transition or F5).
    // Releases old GPU buffers before creating new ones — safe to call multiple times.
    bool RebuildTerrainPatch(const TerrainParams& params);
    // Release the terrain mesh and mark terrain unavailable (for cells with terrain.enabled=false).
    void ClearTerrainPatch();
    float SampleTerrainHeight(float worldX, float worldZ) const;
    bool IsTerrainAvailable() const;
// Gravity and jumping control
    void SetCameraVelocityY(float velocity);
    float GetCameraVelocityY() const;
    void SetIsGrounded(bool grounded);
    bool GetIsGrounded() const;
    ID3D11Device* GetDevice() const;
    ID3D11DeviceContext* GetContext() const;
    int GetRenderWidth() const { return renderWidth; }
    int GetRenderHeight() const { return renderHeight; }
private:
    struct Vertex { float x, y, z; float nx, ny, nz; float r, g, b, a; };
    struct TransformConstantBuffer { DirectX::XMFLOAT4X4 mvp; DirectX::XMFLOAT4X4 world; };
    float cameraX, cameraY, cameraZ;
    float cameraYaw, cameraPitch;
    bool CreateTriangleResources();bool CreateRenderTarget();
	bool CreateTerrainPatch();
    void CreateGroundPlane();
    static HRESULT CompileShaderFromFile(const wchar_t* path, const char* entryPoint, const char* target, ID3DBlob** outBlob);
    float cameraVelocityY; // Vertical velocity for jumping and gravity
    bool isGrounded;       // Whether the camera is on the ground
    int renderWidth;
    int renderHeight;
    void CreateGroundShaders();
	void CreateSkyShaders();
    std::vector<float> m_terrainHeights; // row-major [z * vertsX + x]
    int m_terrainVertsX = 0;
    int m_terrainVertsZ = 0;
    float m_terrainCellSize = 1.0f;
    float m_terrainHalfSizeX = 0.0f;
    float m_terrainHalfSizeZ = 0.0f;
    float m_terrainOriginX = 0.0f;   // world-space X of terrain mesh start
    float m_terrainOriginZ = 0.0f;   // world-space Z of terrain mesh start
    bool m_terrainAvailable = false;
    struct LightConstantBuffer
    {
        DirectX::XMFLOAT4 lightDirection;
       
        DirectX::XMFLOAT4 lightColor;
       
    };
 
    ID3D11Buffer* m_groundVertexBuffer = nullptr;
    ID3D11Buffer* m_groundIndexBuffer = nullptr;
    UINT m_groundIndexCount = 0;
    ID3D11Device* device;
    ID3D11DeviceContext* context;
    IDXGISwapChain* swapChain;
    ID3D11RenderTargetView* renderTargetView;
    D3D_FEATURE_LEVEL featureLevel;
    ID3D11VertexShader* vertexShader;
    ID3D11PixelShader* pixelShader;
    ID3D11InputLayout* inputLayout;
    ID3D11Buffer* vertexBuffer;
    ID3D11Buffer* transformConstantBuffer;
    ID3D11RasterizerState* rasterizerState;
    ID3D11Texture2D* depthTexture;
    ID3D11DepthStencilView* depthView;
    ID3D11Buffer* indexBuffer;
    ID3D11VertexShader* groundVertexShader = nullptr;
    ID3D11PixelShader* groundPixelShader = nullptr;
    ID3D11InputLayout* groundInputLayout = nullptr;
    ID3D11VertexShader* skyVertexShader = nullptr;
    ID3D11PixelShader* skyPixelShader = nullptr;
    ID3D11InputLayout* skyInputLayout = nullptr;
    ID3D11Buffer* lightConstantBuffer = nullptr;
	ID3D11Buffer* m_terrainPatchVertexBuffer = nullptr;
	ID3D11Buffer* m_terrainPatchIndexBuffer = nullptr;
	UINT m_terrainPatchIndexCount = 0;


};  