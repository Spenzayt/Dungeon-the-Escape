#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
    virtual ~Entity() = default;

    virtual void update(float deltaTime, const sf::RenderWindow& window) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif // ENTITY_H