#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Map;

class Player : public Entity {
private:
    float posX;
    float posY;
    float speed;
    int health;
    int maxHealth;
    sf::RectangleShape playerSprite;
    bool hasKey;

    float boostSpeedMultiplier;
    float boostDuration;

    Map* map;

public:
    Player();
    ~Player() override;

    void setMap(Map* newMap);

    float getPosX() const;
    float getPosY() const;
    float getSpeed() const;
    bool getHasKey() const;

    void setPosX(float newX);
    void setPosY(float newY);
    void setSpeed(float newSpeed);
    void setHasKey(bool value);

    const sf::RectangleShape& getPlayerSprite() const;

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;

    void handleInput(float deltaTime);
    void limitToScreen(const sf::RenderWindow& window);

    void collectKey();
    bool hasCollectedKey() const;

    void activateSpeedBoost(float multiplier, float duration);

    bool isDead() const;
    void loseHealth();
};

#endif // PLAYER_H