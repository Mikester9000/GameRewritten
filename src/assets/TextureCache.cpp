// TextureCache.cpp
// Loads D3D11 textures via DirectXTex and caches the resulting SRVs.

#define WIN32_LEAN_AND_MEAN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <d3d11.h>

// Include d3d11.h before DirectXTex so the D3D11 helper APIs are compiled in.
#include "DirectXTex.h"

#include "TextureCache.hpp"
#include "logger/Logger.hpp"

// Narrow UTF-8/ASCII path to wide string for DirectXTex APIs.
static std::wstring NarrowToWide(const std::string& src)
{
    if (src.empty()) return {};
    const int needed = MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, nullptr, 0);
    if (needed <= 0) return {};
    // needed includes the null terminator; allocate needed-1 wide chars and
    // pass needed-1 as the buffer count so the null stays in bounds.
    std::wstring wide(static_cast<size_t>(needed) - 1, L'\0');
    MultiByteToWideChar(CP_UTF8, 0, src.c_str(), -1, &wide[0], needed - 1);
    return wide;
}

// Route to the correct DirectXTex loader based on file extension.
static HRESULT LoadAuto(const wchar_t* path,
                        DirectX::TexMetadata& metadata,
                        DirectX::ScratchImage& image)
{
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

    // Default: WIC handles PNG, JPG, BMP, TIFF, etc.
    return DirectX::LoadFromWICFile(path, DirectX::WIC_FLAGS_NONE, &metadata, image);
}

ID3D11ShaderResourceView* TextureCache::Load(ID3D11Device* device, const std::string& path)
{
    if (!device || path.empty())
        return nullptr;

    // Return cached SRV if already loaded.
    auto it = m_cache.find(path);
    if (it != m_cache.end())
        return it->second;

    const std::wstring widePath = NarrowToWide(path);
    if (widePath.empty())
    {
        LOG_WARN("TextureCache::Load: failed to convert path to wide string: " + path);
        m_cache[path] = nullptr; // cache the failure so we don't retry every frame
        return nullptr;
    }

    DirectX::TexMetadata  metadata{};
    DirectX::ScratchImage image;

    HRESULT hr = LoadAuto(widePath.c_str(), metadata, image);
    if (FAILED(hr))
    {
        LOG_WARN("TextureCache::Load: failed to load texture: " + path);
        m_cache[path] = nullptr; // cache the failure so we don't retry every frame
        return nullptr;
    }

    ID3D11ShaderResourceView* srv = nullptr;
    hr = DirectX::CreateShaderResourceView(
        device,
        image.GetImages(),
        image.GetImageCount(),
        metadata,
        &srv);

    if (FAILED(hr) || !srv)
    {
        LOG_WARN("TextureCache::Load: failed to create SRV for: " + path);
        m_cache[path] = nullptr;
        return nullptr;
    }

    m_cache[path] = srv;
    return srv;
}

void TextureCache::ReleaseAll()
{
    for (auto& pair : m_cache)
    {
        if (pair.second)
            pair.second->Release();
    }
    m_cache.clear();
}
