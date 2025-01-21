#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "enemy.h"
#include "player.h"
#include "chaserEnemy.h"
#include "patrollingEnemy.h"
#include <vector>
#include <memory>

class EnemyManager {
private:
    std::vector<std::shared_ptr<Enemy>> enemies;

public:
    enum EnemyType
    {
        CHASER,
        PATROLLING
    };

    EnemyManager();
    ~EnemyManager();

    void spawnEnemy(int numberOfEnemies, EnemyType type, float posX, float posY);
    void updateEnemies(float deltaTime, const Player& player);
    void renderEnemies(sf::RenderWindow& window);
};

#endif // ENEMYMANAGER_H