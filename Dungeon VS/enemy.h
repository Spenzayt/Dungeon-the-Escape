#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
public:
    virtual ~Enemy() = default;


    virtual void update(float deltaTime, const sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // ENEMY_H