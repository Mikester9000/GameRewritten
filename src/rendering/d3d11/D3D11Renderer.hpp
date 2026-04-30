#pragma once
#include <windows.h>
#include <d3d11.h>
#include <DirectXMath.h>

// A simple class for setting up and drawing with Direct3D 11.
class D3D11Renderer
{
public:
    D3D11Renderer();
    bool Initialize(HWND windowHandle, int width, int height);
    void Shutdown();
    void ClearScreen(float red, float green, float blue, float alpha);
    void PresentFrame();
    void DrawRotatingTriangle();
    void SetCameraPosition(float x, float y, float z);
    void SetCameraRotation(float yaw, float pitch);
    void GetCameraPosition(float& x, float& y, float& z) const;
    void GetCameraRotation(float& yaw, float& pitch) const;
    // Gravity and jumping control
    void SetCameraVelocityY(float velocity);
    float GetCameraVelocityY() const;
    void SetIsGrounded(bool grounded);
    bool GetIsGrounded() const;
private:
    struct Vertex { float x, y, z; float r, g, b, a; };
    struct TransformConstantBuffer { DirectX::XMFLOAT4X4 mvp; };
    float cameraX, cameraY, cameraZ;
    float cameraYaw, cameraPitch;
    bool CreateRenderTarget();
    bool CreateTriangleResources();
    static HRESULT CompileShaderFromFile(const wchar_t* path, const char* entryPoint, const char* target, ID3DBlob** outBlob);
    float cameraVelocityY; // Vertical velocity for jumping and gravity
    bool isGrounded;       // Whether the camera is on the ground
    int renderWidth;
    int renderHeight;

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
};  