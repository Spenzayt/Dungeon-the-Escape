#include "potion.h"
#include <iostream>

Potion::Potion(float x, float y) : isCollected(false) {
    if (!texture.loadFromFile("assets/objects/potion.png")) {
        std::cerr << "Erreur de chargement de la texture de la clé!" << std::endl;
    }

    sprite.setTexture(texture);
    sprite.setScale(50.f / texture.getSize().x, 50.f / texture.getSize().y);
    sprite.setPosition(x, y);
}

void Potion::update(float deltaTime, const sf::RenderWindow& window) {
    if (isCollected) return;
}

void Potion::draw(sf::RenderWindow& window) {
    if (!isCollected) {
        window.draw(sprite);
    }
}

bool Potion::isPotionCollected() const {
    return isCollected;
}

void Potion::collectPotion() {
    isCollected = true;
}

sf::FloatRect Potion::getBounds() const {
    return sprite.getGlobalBounds();
}