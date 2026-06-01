#include "item_comparison.h"

namespace gr
{
ItemComparisonResult ItemComparisonTooltip::Compare(const std::vector<ItemStatLine>& statLines) const
{
    ItemComparisonResult result;
    result.lines = statLines;
    return result;
}
} // namespace gr
