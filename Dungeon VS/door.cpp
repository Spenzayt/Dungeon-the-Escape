#include "Door.h"
#include <iostream>

Door::Door(const sf::Vector2f& position) : state(CLOSED) {
    sprite.setScale(2.f, 2.f);
    sprite.setPosition(position);

    if (!textureClosed.loadFromFile("assets/objects/closeDoor.png")) {
        std::cerr << "Erreur de chargement de la texture de la porte fermée: assets/objects/closeDoor.png" << std::endl;
    }

    if (!textureOpen.loadFromFile("assets/objects/openDoor.png")) {
        std::cerr << "Erreur de chargement de la texture de la porte ouverte: assets/objects/openDoor.png" << std::endl;
    }

    sprite.setTexture(textureClosed);
}

void Door::open() {
    if (state == CLOSED) {
        state = OPEN;
        sprite.setTexture(textureOpen);
    }
}

void Door::close() {
    if (state == OPEN) {
        state = CLOSED;
        sprite.setTexture(textureClosed);
    }
}

bool Door::isOpen() const {
    return state == OPEN;
}

void Door::update(float deltaTime, const sf::RenderWindow& window) {}

void Door::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Door::getBounds() const {
    return sprite.getGlobalBounds();
}