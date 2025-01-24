#include "Player.h"
#include <iostream>
#include "map.h" 

Player::Player() : posX(100.f), posY(900.f), health(3), maxHealth(3), speed(800.0f), boostSpeedMultiplier(1.f), boostDuration(0.f), hasKey(false), map(nullptr) {
    playerSprite.setSize(sf::Vector2f(60.f, 60.f));
    playerSprite.setFillColor(sf::Color::Green);
    playerSprite.setPosition(posX, posY);
}

Player::~Player() {}

void Player::setMap(Map* newMap) {
    map = newMap;
}

float Player::getPosX() const {
    return posX;
}
float Player::getPosY() const {
    return posY;
}
float Player::getSpeed() const {
    return speed;
}
bool Player::getHasKey() const {
    return hasKey;
}

void Player::setPosX(float newX) {
    posX = newX;
}
void Player::setPosY(float newY) {
    posY = newY;
}
void Player::setSpeed(float newSpeed) {
    speed = newSpeed;
}
void Player::setHasKey(bool value) {
    hasKey = value;
}

const sf::RectangleShape& Player::getPlayerSprite() const {
    return playerSprite;
}

void Player::handleInput(float deltaTime) {
    float adjustedSpeed = speed * boostSpeedMultiplier;

    float newPosX = posX;
    float newPosY = posY;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        newPosX -= adjustedSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        newPosX += adjustedSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        newPosY -= adjustedSpeed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        newPosY += adjustedSpeed * deltaTime;
    }

    sf::FloatRect newPlayerBounds(newPosX, newPosY, playerSprite.getSize().x, playerSprite.getSize().y);

    if (map && !map->checkWallCollision(newPlayerBounds)) {
        posX = newPosX;
        posY = newPosY;
    }
}

void Player::limitToScreen(const sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();

    float windowWidth = static_cast<float>(windowSize.x);
    float windowHeight = static_cast<float>(windowSize.y);

    if (posX < 0.f) {
        posX = 0.f;
    }

    if (posX + playerSprite.getSize().x > windowWidth) {
        posX = windowWidth - playerSprite.getSize().x;
    }

    if (posY < 0.f) {
        posY = 0.f;
    }

    if (posY + playerSprite.getSize().y > windowHeight) {
        posY = windowHeight - playerSprite.getSize().y;
    }
}

void Player::update(float deltaTime, const sf::RenderWindow& window) {
    if (boostDuration > 0.f) {
        boostDuration -= deltaTime;
        if (boostDuration <= 0.f) {
            boostSpeedMultiplier = 1.f;
        }
    }


    handleInput(deltaTime);
    limitToScreen(window);
}

void Player::draw(sf::RenderWindow& window) {
    playerSprite.move(static_cast<float>(posX - playerSprite.getPosition().x),
        static_cast<float>(posY - playerSprite.getPosition().y));
    window.draw(playerSprite);
}

void Player::collectKey() {
    hasKey = true;
    std::cout << "Clé collectée !" << std::endl;
}

bool Player::hasCollectedKey() const {
    return hasKey;
}

void Player::activateSpeedBoost(float multiplier, float duration) {
    boostSpeedMultiplier = multiplier;
    boostDuration = duration;
}

bool Player::isDead() const {
    return health <= 0;
}

void Player::loseHealth() {
    health--;
}