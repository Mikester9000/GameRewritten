// tp_image.cpp — Image loading wrapper (stb_image).

// Tell stb_image to compile its implementation here.
#define STB_IMAGE_IMPLEMENTATION
#include "../../third_party/stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../../third_party/stb/stb_image_write.h"

#include "tp_image.hpp"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace tp
{

bool Image::Load(const std::string& path, Image& out)
{
    out.pixels = stbi_load(path.c_str(), &out.width, &out.height, &out.channels, 4);
    if (!out.pixels)
    {
        std::string msg = "[ThirdParty][Image] Failed to load: " + path +
                          " (" + (stbi_failure_reason() ? stbi_failure_reason() : "unknown") + ")\n";
        OutputDebugStringA(msg.c_str());
        return false;
    }
    out.channels = 4; // we always request RGBA from stb
    std::string msg = "[ThirdParty][Image] Loaded " + path +
                      " (" + std::to_string(out.width) + "x" + std::to_string(out.height) + ")\n";
    OutputDebugStringA(msg.c_str());
    return true;
}

void Image::Free()
{
    if (pixels)
    {
        stbi_image_free(pixels);
        pixels   = nullptr;
        width    = 0;
        height   = 0;
        channels = 0;
    }
}

} // namespace tp
