#pragma once

#include <set>
#include <vector>

struct RegionCoord
{
    int rx = 0;
    int rz = 0;

    bool operator<(const RegionCoord& rhs) const
    {
        if (rx != rhs.rx)
            return rx < rhs.rx;
        return rz < rhs.rz;
    }
};

class WorldPartition
{
public:
    void SetRegionSizeCells(int cellsPerRegion);
    int GetRegionSizeCells() const { return m_regionSizeCells; }

    RegionCoord RegionFromCell(int cx, int cz) const;
    void UpdateActiveRegions(int playerCX, int playerCZ, int regionRadius);
    std::vector<RegionCoord> GetActiveRegions() const;

private:
    int m_regionSizeCells = 4;
    std::set<RegionCoord> m_activeRegions;
};
