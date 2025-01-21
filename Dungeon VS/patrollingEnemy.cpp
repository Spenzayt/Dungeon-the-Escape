#include "patrollingEnemy.h"

PatrollingEnemy::PatrollingEnemy(float x, float y) : speed(400.0f) {
    enemySprite.setSize({ 60.0f, 60.0f });
    enemySprite.setFillColor(sf::Color::Red);
    enemySprite.setPosition(x, y);
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