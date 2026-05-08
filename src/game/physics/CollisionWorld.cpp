#include "CollisionWorld.hpp"

void CollisionWorld::AddBox(float cx, float cy, float cz, float hw, float hh, float hd)
{
    m_staticBlockers.push_back(AABB::FromCenter(cx, cy, cz, hw, hh, hd));
}

void CollisionWorld::Clear()
{
    m_staticBlockers.clear();
}

void CollisionWorld::ResolveMovement(float& x, float& y, float& z, float hw, float hh, float hd) const
{
    AABB player = AABB::FromCenter(x, y, z, hw, hh, hd);

    // Keep this bounded to avoid pathological/infinite push loops in dense overlaps.
    // If this cap is reached, the player remains at the last corrected position.
    static constexpr int MAX_SOLVER_ITERATIONS = 8;
    for (int iteration = 0; iteration < MAX_SOLVER_ITERATIONS; ++iteration)
    {
        bool correctedThisIteration = false;
        for (const AABB& blocker : m_staticBlockers)
        {
            if (!player.Overlaps(blocker))
                continue;

            const float pushPosX = blocker.maxX - player.minX;
            const float pushNegX = player.maxX - blocker.minX;
            const float pushPosY = blocker.maxY - player.minY;
            const float pushNegY = player.maxY - blocker.minY;
            const float pushPosZ = blocker.maxZ - player.minZ;
            const float pushNegZ = player.maxZ - blocker.minZ;

            float bestMagnitude = pushPosX;
            float moveX = bestMagnitude;
            float moveY = 0.0f;
            float moveZ = 0.0f;

            if (pushNegX < bestMagnitude)
            {
                bestMagnitude = pushNegX;
                moveX = -pushNegX;
                moveY = 0.0f;
                moveZ = 0.0f;
            }
            if (pushPosY < bestMagnitude)
            {
                bestMagnitude = pushPosY;
                moveX = 0.0f;
                moveY = pushPosY;
                moveZ = 0.0f;
            }
            if (pushNegY < bestMagnitude)
            {
                bestMagnitude = pushNegY;
                moveX = 0.0f;
                moveY = -pushNegY;
                moveZ = 0.0f;
            }
            if (pushPosZ < bestMagnitude)
            {
                bestMagnitude = pushPosZ;
                moveX = 0.0f;
                moveY = 0.0f;
                moveZ = pushPosZ;
            }
            if (pushNegZ < bestMagnitude)
            {
                bestMagnitude = pushNegZ;
                moveX = 0.0f;
                moveY = 0.0f;
                moveZ = -pushNegZ;
            }

            x += moveX;
            y += moveY;
            z += moveZ;
            player = AABB::FromCenter(x, y, z, hw, hh, hd);
            correctedThisIteration = true;
            break; // exit inner scan; outer loop then starts a fresh blocker scan
        }

        if (!correctedThisIteration)
            break;
    }
}
