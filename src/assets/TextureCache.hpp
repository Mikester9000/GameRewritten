// ============================================================
// FILE: src/assets/TextureCache.hpp
// SYSTEM: TextureCache.hpp
// SYSTEM: asset registry lookups and content loading helpers

#pragma once
// TextureCache.hpp
// Loads D3D11 shader resource views from disk via DirectXTex and caches them
// by file path so each texture is uploaded to GPU only once.

#include <d3d11.h>
#include <string>
#include <unordered_map>

class TextureCache
{
public:
    // Load a texture from disk and return its SRV, or return a cached SRV if
    // the path was already loaded.  Returns nullptr on failure — never crashes.
    // Accepts .dds and .png (and any WIC-supported format).
    ID3D11ShaderResourceView* Load(ID3D11Device* device, const std::string& path);

    // Release every cached SRV and clear the map.
    // Call this before renderer shutdown.
    void ReleaseAll();

private:
    std::unordered_map<std::string, ID3D11ShaderResourceView*> m_cache;
};
