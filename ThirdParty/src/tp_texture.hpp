#pragma once
// tp_texture.hpp — DirectXTex runtime texture loading wrapper (MIT licence).
//
// Provides CPU-side image loading via DirectXTex (WIC for PNG/JPG/BMP/TIFF,
// native DDS loader, TGA, and HDR).  The loaded data lives in CPU memory;
// upload to a D3D11 texture is a future step.
//
// Usage:
//   tp::TextureInfo info;
//   if (tp::Texture::LoadFromFile(L"Content/Textures/diffuse.png", info))
//       // info.width / height / format / mipLevels are valid
//
// Startup smoke test (called once in Main.cpp):
//   tp::Texture::SmokeTest();
//
// Note: stb_image (tp_image) is NOT replaced; both coexist.
//       DirectXTex adds DDS/BCn support that stb_image lacks.

#include <cstdint>
#include <string>

namespace tp
{

// Metadata returned by a successful texture load.
struct TextureInfo
{
    size_t   width     = 0;
    size_t   height    = 0;
    size_t   mipLevels = 0;
    uint32_t format    = 0;   // DXGI_FORMAT value (0 = unknown)
    bool     isValid   = false;
};

class Texture
{
public:
    // Load an image from disk into CPU memory using DirectXTex.
    // Accepts WIC formats (PNG, JPG, BMP, TIFF), DDS, TGA, and HDR.
    // Wide-char path required for Windows filesystem compatibility.
    // Returns true on success and populates out.
    static bool LoadFromFile(const wchar_t* path, TextureInfo& out);

    // Narrow-string convenience overload (UTF-8 or ASCII paths).
    static bool LoadFromFile(const char* path, TextureInfo& out);

    // One-shot startup smoke test.
    // Attempts to load Content/Textures/placeholder.png and logs the result.
    // Fails gracefully with a log message if the file is absent.
    static void SmokeTest();

private:
    Texture() = delete;
};

} // namespace tp
