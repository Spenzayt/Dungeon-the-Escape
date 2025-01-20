#include "chaserEnemy.h"

ChaserEnemy::ChaserEnemy() : speed(400.0f), isChasing(false) {
    enemySprite.setSize({ 50.0f, 50.0f });
    enemySprite.setFillColor(sf::Color::Cyan);

    int randomX = rand() % (1920 - static_cast<int>(enemySprite.getSize().x));
    int randomY = rand() % (1080 - static_cast<int>(enemySprite.getSize().y));

    enemySprite.setPosition(static_cast<float>(randomX), static_cast<float>(randomY));
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