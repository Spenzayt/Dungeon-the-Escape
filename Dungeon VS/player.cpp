#include "Player.h"

Player::Player() : posX(960), posY(540), speed(800.0f) {
    playerSprite.setSize(sf::Vector2f(60.f, 60.f));
    playerSprite.setFillColor(sf::Color::Green);
    playerSprite.setPosition(static_cast<float>(posX), static_cast<float>(posY));
}

Player::~Player() {}

int Player::getPosX() const {
    return posX;
}
int Player::getPosY() const {
    return posY;
}
float Player::getSpeed() const {
    return speed;
}

void Player::setPosX(int newX) {
    posX = newX;
}
void Player::setPosY(int newY) {
    posY = newY;
}
void Player::setSpeed(float newSpeed) {
    speed = newSpeed;
}

const sf::RectangleShape& Player::getPlayerSprite() const {
    return playerSprite;
}

void Player::handleInput(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        posX -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        posX += speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        posY -= speed * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        posY += speed * deltaTime;
    }
}

void Player::limitToScreen(const sf::RenderWindow& window) {
    sf::Vector2u windowSize = window.getSize();

    if (posX < 0) {
        posX = 0;
    }

    if (posX + playerSprite.getSize().x > windowSize.x) {
        posX = windowSize.x - playerSprite.getSize().x;
    }

    if (posY < 0) {
        posY = 0;
    }

    if (posY + playerSprite.getSize().y > windowSize.y) {
        posY = windowSize.y - playerSprite.getSize().y;
    }
}

void Player::update(float deltaTime, const sf::RenderWindow& window) {
    handleInput(deltaTime);
    limitToScreen(window);
}

void Player::draw(sf::RenderWindow& window) {
    playerSprite.move(static_cast<float>(posX - playerSprite.getPosition().x),
        static_cast<float>(posY - playerSprite.getPosition().y));
    window.draw(playerSprite);
}