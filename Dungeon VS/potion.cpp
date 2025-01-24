#include "potion.h"
#include "player.h"
#include <iostream>

Potion::Potion(float x, float y, Player* player)
    : isCollected(false), player(player) {
    if (!texture.loadFromFile("assets/objects/potion.png")) {
        std::cerr << "Erreur de chargement de la texture de la potion !" << std::endl;
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

    if (player) {
        player->activateSpeedBoost(2.f, 5.0f);
    }

    std::cout << "Potion ramassée !" << std::endl;
}

sf::FloatRect Potion::getBounds() const {
    return sprite.getGlobalBounds();
}