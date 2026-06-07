#include "slot_naming.h"

#include <cctype>

namespace gr
{
std::string SaveSlotNaming::Sanitize(const std::string& rawName, std::size_t maxLength)
{
    std::string out;
    out.reserve(rawName.size());

    for (char ch : rawName)
    {
        const unsigned char c = static_cast<unsigned char>(ch);
        if (std::isalnum(c) || ch == ' ' || ch == '-' || ch == '_')
        {
            out.push_back(ch);
        }

        if (out.size() >= maxLength)
        {
            break;
        }
    }

    while (!out.empty() && out.back() == ' ')
    {
        out.pop_back();
    }

    if (out.empty())
    {
        out = "Save Slot";
    }
    return out;
}
} // namespace gr
