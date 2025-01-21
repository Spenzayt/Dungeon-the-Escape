#ifndef KEY_H
#define KEY_H

#include "entity.h"
#include <SFML/Graphics.hpp>

class Key : public Entity {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool isCollected;

public:
    Key(float x, float y);
    ~Key() override = default;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    bool isKeyCollected() const;
    void collectKey();
    sf::FloatRect getBounds() const;
};

#endif // KEY_H