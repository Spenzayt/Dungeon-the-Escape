#include "key.h"
#include <iostream>

Key::Key(float x, float y) : isCollected(false) {
    if (!texture.loadFromFile("assets/objects/key.png")) {
        std::cerr << "Erreur de chargement de la texture de la clé!" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale(50.f / texture.getSize().x, 50.f / texture.getSize().y);
    sprite.setPosition(x, y);
}

void Key::update(float deltaTime, const sf::RenderWindow& window) {
    if (isCollected) return;

}

void Key::draw(sf::RenderWindow& window) {
    if (!isCollected) {
        window.draw(sprite);
    }
}

bool Key::isKeyCollected() const {
    return isCollected;
}

void Key::collectKey() {
    isCollected = true;
}

sf::FloatRect Key::getBounds() const {
    return sprite.getGlobalBounds();
}