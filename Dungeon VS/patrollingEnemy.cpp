#include "patrollingEnemy.h"

PatrollingEnemy::PatrollingEnemy() {
    speed = 150.0f;
    enemySprite.setFillColor(sf::Color::Yellow);
}

PatrollingEnemy::~PatrollingEnemy() {}

void PatrollingEnemy::update(float deltaTime, const sf::RenderWindow& window) {

}

void PatrollingEnemy::draw(sf::RenderWindow& window) {
    enemySprite.move(static_cast<float>(posX - enemySprite.getPosition().x),
        static_cast<float>(posY - enemySprite.getPosition().y));
    window.draw(enemySprite);
}