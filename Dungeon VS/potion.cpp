#include "potion.h"

Potion::Potion(float x, float y) : isCollected(false) {
    potionShape.setSize(sf::Vector2f(30.f, 30.f));
    potionShape.setFillColor(sf::Color::Magenta);
    potionShape.setPosition(x, y);
}

void Potion::update(float deltaTime, const sf::RenderWindow& window) {
    if (isCollected) return;
}

void Potion::draw(sf::RenderWindow& window) {
    if (!isCollected) {
        window.draw(potionShape);
    }
}

bool Potion::isPotionCollected() const {
    return isCollected;
}

void Potion::collectPotion() {
    isCollected = true;
}

sf::FloatRect Potion::getBounds() const {
    return potionShape.getGlobalBounds();
}