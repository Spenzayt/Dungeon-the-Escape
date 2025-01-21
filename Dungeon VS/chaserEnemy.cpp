#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy(float x, float y) : speed(400.0f), isChasing(false) {
    enemySprite.setSize({ 60.0f, 60.0f });
    enemySprite.setFillColor(sf::Color::Cyan);
    enemySprite.setPosition(x, y);
}

ChaserEnemy::~ChaserEnemy() {}

void ChaserEnemy::update(float deltaTime, const Player& player) {
    if (isChasing) {
        moveTowards(player, deltaTime);
    }

    if (hitPlayer(player)) {
        // hit
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

void ChaserEnemy::moveTowards(const Player& player, float deltaTime) {
    sf::Vector2f position = enemySprite.getPosition();
    sf::Vector2f direction = sf::Vector2f(static_cast<float>(player.getPosX()), static_cast<float>(player.getPosY())) - position;

    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length > 0.0f) {
        direction /= length; 
    }

    enemySprite.move(direction * speed * deltaTime);
}

bool ChaserEnemy::hitPlayer(const Player& player) {
    sf::FloatRect enemyBounds = enemySprite.getGlobalBounds();
    sf::FloatRect playerBounds = player.getPlayerSprite().getGlobalBounds();

    return enemyBounds.intersects(playerBounds);
}