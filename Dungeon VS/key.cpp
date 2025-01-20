#include "key.h"

Key::Key(float x, float y) : isCollected(false) {
    keyShape.setSize(sf::Vector2f(25.f, 25.f));
    keyShape.setFillColor(sf::Color::Yellow);
    keyShape.setPosition(x, y);
}

void Key::update(float deltaTime, const sf::RenderWindow& window) {

}

void Key::draw(sf::RenderWindow& window) {
    if (!isCollected) {
        window.draw(keyShape);
    }
}

bool Key::isKeyCollected() const {
    return isCollected;
}

void Key::collectKey() {
    isCollected = true;
}

sf::FloatRect Key::getBounds() const {
    return keyShape.getGlobalBounds();
}