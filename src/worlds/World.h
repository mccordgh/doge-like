#pragma once

class World
{
  public:
    std::vector<Entity*> colliders;
    std::vector<Entity*> enemies;
    std::vector<Entity*> players;
    std::vector<Entity*> projectiles;
    std::vector<Entity*> tiles;

    enum groupLabels : std::size_t
    {
        groupColliders,
        groupEnemies,
        groupMap,
        groupPlayers,
        groupProjectiles,
    };

    World(Manager* man);
    ~World();

    void update();
    void draw(SDL_Renderer* renderer);

  private:
    Manager* manager;
    Entity* player;

    void init();
};
