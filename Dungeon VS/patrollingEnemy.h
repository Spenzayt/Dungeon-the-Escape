#ifndef PATROLLING_ENEMY_H
#define PATROLLING_ENEMY_H

#include "enemy.h"

class PatrollingEnemy : public Enemy {
public:
    PatrollingEnemy();
    ~PatrollingEnemy() override;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
};

#endif // PATROLLING_ENEMY_H