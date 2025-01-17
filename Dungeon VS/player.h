#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity {
private:
    int posX;
    int posY;
    float speed;
    sf::RectangleShape playerSprite;

public:
    Player();
    ~Player() override;

    int getPosX() const;
    int getPosY() const;
    float getSpeed() const;

    void setPosX(int newX);
    void setPosY(int newY);
    void setSpeed(float newSpeed);

    void update(float deltaTime, const sf::RenderWindow& window) override;
    void draw(sf::RenderWindow& window) override;

    void handleInput(float deltaTime);
    void limitToScreen(const sf::RenderWindow& window);
};

#endif // PLAYER_H