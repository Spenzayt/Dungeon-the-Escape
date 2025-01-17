#include "chaserEnemy.h"
#include <cmath>

ChaserEnemy::ChaserEnemy() : isChasing(false) {
    speed = 400.0f;
    enemySprite.setFillColor(sf::Color::Cyan);
}

ChaserEnemy::~ChaserEnemy() {}

void ChaserEnemy::update(float deltaTime, const sf::RenderWindow& window, const Player& player) {
    if (isChasing) {
        // Position du joueur
        sf::Vector2f playerPos = player.getPosition();

        // Calcul du vecteur direction
        float deltaX = playerPos.x - enemySprite.getPosition().x;
        float deltaY = playerPos.y - enemySprite.getPosition().y;

        // Normalisation du vecteur direction
        float magnitude = std::sqrt(deltaX * deltaX + deltaY * deltaY);
        if (magnitude != 0) {
            deltaX /= magnitude;
            deltaY /= magnitude;
        }

        // Déplacement de l'ennemi
        enemySprite.move(deltaX * speed * deltaTime, deltaY * speed * deltaTime);
    }
}

void ChaserEnemy::draw(sf::RenderWindow& window) {
    window.draw(enemySprite);
}

void ChaserEnemy::startChasing() {
    isChasing = true;
}

void ChaserEnemy::stopChasing() {
    isChasing = false;
}

bool ChaserEnemy::getIsChasing() const {
    return isChasing;
}