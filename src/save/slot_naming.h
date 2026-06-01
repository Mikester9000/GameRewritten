#pragma once

#include <cstddef>
#include <string>

namespace gr
{
class SaveSlotNaming
{
public:
    static std::string Sanitize(const std::string& rawName, std::size_t maxLength = 24);
};
} // namespace gr
