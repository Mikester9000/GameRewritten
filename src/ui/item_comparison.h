#pragma once

#include <string>
#include <vector>

namespace gr
{
struct ItemStatLine
{
    std::string name;
    int currentValue = 0;
    int candidateValue = 0;
};

struct ItemComparisonResult
{
    std::vector<ItemStatLine> lines;
};

class ItemComparisonTooltip
{
public:
    ItemComparisonResult Compare(const std::vector<ItemStatLine>& statLines) const;
};
} // namespace gr
