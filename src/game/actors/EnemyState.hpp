#pragma once
enum class EnemyState
{
    Patrol,   // walking between waypoints
    Chase,    // moving toward player
    Attack,   // wind-up before dealing damage
    Hit,      // brief stagger after taking damage
    Dead      // waiting to despawn
};
