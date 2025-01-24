#include "patrollingEnemy.h"
#include <cmath>

PatrollingEnemy::PatrollingEnemy(float x, float y)
    : speed(600.f), initialPosition(x, y), currentSide(0), distanceTraveled(0.0f), sideLength(180.0f) {
    enemySprite.setSize({ 60.0f, 60.0f });
    enemySprite.setFillColor(sf::Color::Red);
    enemySprite.setPosition(x, y);
}

PatrollingEnemy::~PatrollingEnemy() {}

void PatrollingEnemy::update(float deltaTime, const Player& player) {
    float movement = speed * deltaTime;
    sf::Vector2f movementVector(0.0f, 0.0f);

    switch (currentSide) {
    case 0:
        movementVector.x = movement;
        break;
    case 1:
        movementVector.y = movement;
        break;
    case 2:
        movementVector.x = -movement;
        break;
    case 3:
        movementVector.y = -movement;
        break;
    }

    enemySprite.move(movementVector);
    distanceTraveled += std::abs(movement);

    if (distanceTraveled >= sideLength) {
        distanceTraveled = 0.0f;
        currentSide = (currentSide + 1) % 4;
    }

    if (hitPlayer(player)) {
        const_cast<Player&>(player).loseHealth();
    }
}

void PatrollingEnemy::draw(sf::RenderWindow& window) {
    window.draw(enemySprite);
}

bool PatrollingEnemy::hitPlayer(const Player& player) {
    sf::FloatRect enemyBounds = enemySprite.getGlobalBounds();
    sf::FloatRect playerBounds = player.getPlayerSprite().getGlobalBounds();

    return enemyBounds.intersects(playerBounds);
}
