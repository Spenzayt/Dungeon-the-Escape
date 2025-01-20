#include "patrollingEnemy.h"

PatrollingEnemy::PatrollingEnemy() : speed(400.0f) {
    enemySprite.setSize({ 50.0f, 50.0f });
    enemySprite.setFillColor(sf::Color::Red);

    int randomX = rand() % (1920 - static_cast<int>(enemySprite.getSize().x));
    int randomY = rand() % (1080 - static_cast<int>(enemySprite.getSize().y));

    enemySprite.setPosition(static_cast<float>(randomX), static_cast<float>(randomY));
}

PatrollingEnemy::~PatrollingEnemy() {}

void PatrollingEnemy::update(float deltaTime, const Player& player) {
    patrolling();

    if (hitPlayer(player)) {
        // hit
    }
}

void PatrollingEnemy::draw(sf::RenderWindow& window) {
    window.draw(enemySprite);
}

void PatrollingEnemy::patrolling() {
    // Patrolling
}

bool PatrollingEnemy::hitPlayer(const Player& player) {
    sf::FloatRect enemyBounds = enemySprite.getGlobalBounds();
    sf::FloatRect playerBounds = player.getPlayerSprite().getGlobalBounds();

    return enemyBounds.intersects(playerBounds);
}