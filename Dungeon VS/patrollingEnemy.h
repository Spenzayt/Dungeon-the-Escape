#ifndef PATROLLINGENEMY_H
#define PATROLLINGENEMY_H

#include "enemy.h"
#include "player.h"
#include <SFML/Graphics.hpp>

class PatrollingEnemy : public Enemy {
private:
    sf::RectangleShape enemySprite;
    float speed;

    sf::Vector2f initialPosition;
    int currentSide;
    float distanceTraveled;
    float sideLength;

public:
    PatrollingEnemy(float x, float y);
    virtual ~PatrollingEnemy();

    virtual void update(float deltaTime, const Player& player) override;
    virtual void draw(sf::RenderWindow& window) override;

    bool hitPlayer(const Player& player);
};

#endif // PATROLLINGENEMY_H