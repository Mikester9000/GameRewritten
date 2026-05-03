// tp_texture.cpp — DirectXTex runtime texture loading wrapper.
// Wraps DirectXTex CPU-side loading (WIC, DDS, TGA, HDR).
// Does NOT upload to GPU — that is a future step via DirectXTex D3D11 helpers.

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <wincodec.h>
#pragma comment(lib, "windowscodecs.lib")

// DirectXTex public header.
// No D3D header is included before this, so D3D-specific APIs are guarded
// out — that is fine; we only use the CPU-side ScratchImage / TexMetadata API.
#include "../../third_party/DirectXTex/DirectXTex.h"

#include "tp_texture.hpp"

#include <string>
#include <sstream>
#include <iomanip>

namespace tp
{

// ── internal helpers ────────────────────────────────────────────────────────

// Convert a narrow UTF-8/ASCII path to a wide string for DirectXTex APIs.
static std::wstring NarrowToWide(const char* src)
{
    if (!src || *src == '\0') return {};
    int needed = MultiByteToWideChar(CP_UTF8, 0, src, -1, nullptr, 0);
    if (needed <= 0) return {};
    std::wstring wide(static_cast<size_t>(needed) - 1, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, src, -1, &wide[0], needed);
    return wide;
}

// Attempt to sniff the file extension and route to the correct DirectXTex loader.
// Returns S_OK and sets metadata on success.
static HRESULT LoadAuto(const wchar_t* path,
                        DirectX::TexMetadata& metadata,
                        DirectX::ScratchImage&  image)
{
    // Determine extension (lower-case compare).
    const wchar_t* ext = nullptr;
    for (const wchar_t* p = path; *p; ++p)
        if (*p == L'.') ext = p;

    if (ext)
    {
        wchar_t extLow[8] = {};
        for (int i = 0; i < 7 && ext[i]; ++i)
            extLow[i] = static_cast<wchar_t>(towlower(ext[i]));

        if (wcscmp(extLow, L".dds") == 0)
            return DirectX::LoadFromDDSFile(path, DirectX::DDS_FLAGS_NONE, &metadata, image);

        if (wcscmp(extLow, L".tga") == 0)
            return DirectX::LoadFromTGAFile(path, DirectX::TGA_FLAGS_NONE, &metadata, image);

        if (wcscmp(extLow, L".hdr") == 0)
            return DirectX::LoadFromHDRFile(path, &metadata, image);
    }

    // Default: WIC (handles PNG, JPG, BMP, TIFF, GIF, …)
    return DirectX::LoadFromWICFile(path, DirectX::WIC_FLAGS_NONE, &metadata, image);
}

// ── public API ───────────────────────────────────────────────────────────────

bool Texture::LoadFromFile(const wchar_t* path, TextureInfo& out)
{
    out = {};

    DirectX::TexMetadata   metadata{};
    DirectX::ScratchImage  image;

    HRESULT hr = LoadAuto(path, metadata, image);
    if (FAILED(hr))
    {
        // Convert path to narrow for the log message.
        char narrow[512] = {};
        WideCharToMultiByte(CP_UTF8, 0, path, -1, narrow, sizeof(narrow) - 1, nullptr, nullptr);
        std::ostringstream msg;
        msg << "[ThirdParty][Texture] Failed to load: " << narrow
            << "  HRESULT=0x" << std::hex << std::uppercase << hr << "\n";
        OutputDebugStringA(msg.str().c_str());
        return false;
    }

    out.width     = metadata.width;
    out.height    = metadata.height;
    out.mipLevels = metadata.mipLevels;
    out.format    = static_cast<uint32_t>(metadata.format);
    out.isValid   = true;

    // Narrow path for log.
    char narrow[512] = {};
    WideCharToMultiByte(CP_UTF8, 0, path, -1, narrow, sizeof(narrow) - 1, nullptr, nullptr);
    std::ostringstream msg;
    msg << "[ThirdParty][Texture] Loaded " << narrow
        << " (" << metadata.width << "x" << metadata.height
        << " fmt=" << static_cast<uint32_t>(metadata.format)
        << " mips=" << metadata.mipLevels << ")\n";
    OutputDebugStringA(msg.str().c_str());
    return true;
}

bool Texture::LoadFromFile(const char* path, TextureInfo& out)
{
    return LoadFromFile(NarrowToWide(path).c_str(), out);
}

void Texture::SmokeTest()
{
    TextureInfo info;
    bool ok = LoadFromFile("Content/Textures/placeholder.png", info);
    if (!ok)
    {
        OutputDebugStringA("[ThirdParty][Texture] SmokeTest: placeholder.png "
                           "not found or failed — this is expected on first run.\n");
    }
    else
    {
        std::ostringstream msg;
        msg << "[ThirdParty][Texture] SmokeTest OK: "
            << info.width << "x" << info.height
            << " DXGI_FORMAT=" << info.format << "\n";
        OutputDebugStringA(msg.str().c_str());
    }
}

} // namespace tp
