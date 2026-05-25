#include "WorldPartition.hpp"

#include <algorithm>

namespace
{
int FloorDiv(int value, int divisor)
{
    if (divisor <= 0)
        return 0;

    if (value >= 0)
        return value / divisor;

    return -(((-value) + divisor - 1) / divisor);
}
}

void WorldPartition::SetRegionSizeCells(int cellsPerRegion)
{
    m_regionSizeCells = std::max(1, cellsPerRegion);
}

RegionCoord WorldPartition::RegionFromCell(int cx, int cz) const
{
    RegionCoord out;
    out.rx = FloorDiv(cx, m_regionSizeCells);
    out.rz = FloorDiv(cz, m_regionSizeCells);
    return out;
}

void WorldPartition::UpdateActiveRegions(int playerCX, int playerCZ, int regionRadius)
{
    const RegionCoord center = RegionFromCell(playerCX, playerCZ);
    const int clampedRadius = std::max(0, regionRadius);

    std::set<RegionCoord> next;
    for (int dz = -clampedRadius; dz <= clampedRadius; ++dz)
    {
        for (int dx = -clampedRadius; dx <= clampedRadius; ++dx)
        {
            RegionCoord coord;
            coord.rx = center.rx + dx;
            coord.rz = center.rz + dz;
            next.insert(coord);
        }
    }

    m_activeRegions.swap(next);
}

std::vector<RegionCoord> WorldPartition::GetActiveRegions() const
{
    return std::vector<RegionCoord>(m_activeRegions.begin(), m_activeRegions.end());
}
