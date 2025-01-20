#ifndef PATROLLING_ENEMY_H
#define PATROLLING_ENEMY_H

#include "enemy.h"

class PatrollingEnemy : public Enemy {
private:
    float speed;
    sf::RectangleShape enemySprite;

public:
    PatrollingEnemy();
    ~PatrollingEnemy() override;

    void update(float deltaTime, const Player& player) override;
    void draw(sf::RenderWindow& window) override;

    void patrolling();

    bool hitPlayer(const Player& player);
};

#endif // PATROLLING_ENEMY_H