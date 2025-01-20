#ifndef CHASER_ENEMY_H
#define CHASER_ENEMY_H

#include "enemy.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

class ChaserEnemy : public Enemy {
private:
    float speed;
    sf::RectangleShape enemySprite;
    bool isChasing;

public:
    ChaserEnemy();
    ~ChaserEnemy() override;

    void update(float deltaTime, const Player& player) override;
    void draw(sf::RenderWindow& window) override;

    void startChasing();
    void stopChasing();
    bool getIsChasing() const;

    void moveTowards(const Player& player, float deltaTime);
    bool hitPlayer(const Player& player);
};

#endif // CHASER_ENEMY_H