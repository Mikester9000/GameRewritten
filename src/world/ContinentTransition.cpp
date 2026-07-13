// ContinentTransition.cpp
// Continent boundary crossing detection.

#include "ContinentTransition.hpp"

void ContinentTransition::Init(const ContinentBound& bound)
{
    m_bound       = bound;
    m_current     = bound.fromContinent;
    m_initialized = true;
}

void ContinentTransition::Update(
    const DirectX::XMFLOAT3& playerPos,
    const std::function<void(const std::string&, const std::string&)>& onTransition)
{
    if (!m_initialized) return;

    const bool onFromSide = playerPos.x < m_bound.boundaryX;
    const std::string& expected = onFromSide ? m_bound.fromContinent
                                             : m_bound.toContinent;

    if (expected != m_current)
    {
        const std::string prev = m_current;
        m_current = expected;
        if (onTransition) onTransition(prev, m_current);
    }
}
