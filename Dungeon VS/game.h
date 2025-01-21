#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "player.h"
#include "chaserEnemy.h"
#include "patrollingEnemy.h"
#include "enemyManager.h"
#include "objectManager.h"
#include "map.h"

class Game {
public:
    Game();
    ~Game();

    void run();

private:
    void createWindow();
    void processEvents();
    void update(float deltaTime);
    void render();

    sf::RenderWindow window;
    bool isRunning;
    
    Player player;
    EnemyManager enemyManager;
    ObjectManager objectManager;
    Map map;
};

#endif // GAME_H
