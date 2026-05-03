#pragma once
// tp_image.hpp — Image loading wrapper using stb_image (public domain / MIT).
// Usage:
//   tp::Image img;
//   if (tp::Image::Load("Content/Textures/logo.png", img)) { /* use img.pixels */ }
//   img.Free();

#include <cstdint>
#include <string>

namespace tp
{

// Holds a decoded image loaded from disk.
struct Image
{
    uint8_t* pixels = nullptr; // RGBA bytes, row-major
    int      width  = 0;
    int      height = 0;
    int      channels = 0;    // channels in the source file (3=RGB, 4=RGBA, etc.)

    // Load an image file (PNG, JPG, TGA, BMP, HDR, …) into this struct.
    // Returns true on success; logs errors via OutputDebugString.
    static bool Load(const std::string& path, Image& out);

    // Release the pixel buffer allocated by Load().
    void Free();

    bool IsValid() const { return pixels != nullptr; }
};

} // namespace tp
