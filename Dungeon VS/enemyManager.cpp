#include "enemyManager.h"

EnemyManager::EnemyManager() {}

EnemyManager::~EnemyManager() {
    enemies.clear();
}

void EnemyManager::spawnEnemy(int numberOfEnemies, EnemyType type, float posX, float posY) {
    for (int i = 0; i < numberOfEnemies; ++i) {
        std::shared_ptr<Enemy> newEnemy = nullptr;

        switch (type) {
        case CHASER:
            newEnemy = std::make_shared<ChaserEnemy>(posX, posY);
            break;
        case PATROLLING:
            newEnemy = std::make_shared<PatrollingEnemy>(posX, posY);
            break;
        default:
            break;
        }

        if (newEnemy) {
            enemies.push_back(newEnemy);
        }
    }
}

void EnemyManager::updateEnemies(float deltaTime, const Player& player) {
    for (auto& enemy : enemies) {
        enemy->update(deltaTime, player);
    }
}

void EnemyManager::renderEnemies(sf::RenderWindow& window) {
    for (auto& enemy : enemies) {
        enemy->draw(window);
    }
}
