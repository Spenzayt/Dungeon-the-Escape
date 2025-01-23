#ifndef DOOR_H
#define DOOR_H

#include "Entity.h"
#include <SFML/Graphics.hpp>

class Door : public Entity {
public:
    enum State {
        OPEN,
        CLOSED
    };

    Door(const sf::Vector2f& position);
    ~Door() override = default;

    void open();
    void close();
    bool isOpen() const;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;

    sf::FloatRect getBounds() const;

private:
    State state;
    sf::Sprite sprite;
    sf::Texture textureClosed;
    sf::Texture textureOpen;
};

#endif // DOOR_H