#ifndef CHASER_ENEMY_H
#define CHASER_ENEMY_H

#include "enemy.h"

class ChaserEnemy : public Enemy {
private:
    int posX;
    int posY;
    float speed;
    sf::RectangleShape playerSprite;

    bool isChasing;

public:
    ChaserEnemy();
    ~ChaserEnemy() override;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;

    void startChasing();
    void stopChasing();
    bool getIsChasing() const;
};

#endif // CHASER_ENEMY_H