#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class Enemy {
public:
    virtual ~Enemy() = default;

    virtual void update(float deltaTime, const Player& player) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // ENEMY_H