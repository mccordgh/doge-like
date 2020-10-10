#pragma once

class GameConstants
{
public:
    static const int STANDARD_TILE_SIZE = 16;
    static const int STANDARD_TILE_SCALE = 4;

    static const int GROUP_MAX_SIZE = 32;

    static const int STANDARD_ANIMATION_SPEED = 200;

    static const int STANDARD_MOVE_SPEED = 3;

    static const int STANDARD_MAP_SCALE = 4;

    static const int PLAYER_SPAWN_Y = GameConstants::STANDARD_TILE_SIZE * 5;
    static const int PLAYER_SPAWN_X = GameConstants::STANDARD_TILE_SIZE * 5;
};
