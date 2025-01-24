#ifndef POTION_H
#define POTION_H

#include "entity.h"
#include <SFML/Graphics.hpp>

class Player;

class Potion : public Entity {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    bool isCollected;
    Player* player;

public:
    Potion(float x, float y, Player* player);
    ~Potion() override = default;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;
    bool isPotionCollected() const;
    void collectPotion();
    sf::FloatRect getBounds() const;
};

#endif // POTION_H