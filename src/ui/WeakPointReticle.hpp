#pragma once

class EnemyActor;

class WeakPointReticle
{
public:
    void Draw(const EnemyActor* target,
              float camX, float camY, float camZ,
              float yaw, float pitch,
              float vpW, float vpH,
              float opacity) const;
};
