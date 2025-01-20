#ifndef POTION_H
#define POTION_H

#include "entity.h"
#include <SFML/Graphics.hpp>

class Potion : public Entity {
private:
    sf::RectangleShape potionShape;
    bool isCollected;

public:
    Potion(float x, float y);
    ~Potion() override = default;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    bool isPotionCollected() const;
    void collectPotion();
    sf::FloatRect getBounds() const;
};

#endif // POTION_H