#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "entity.h"
#include "key.h"
#include "potion.h"
#include <vector>
#include <memory>
#include "player.h"

class ObjectManager {
private:
    std::vector<std::shared_ptr<Entity>> objects;

public:
    enum ObjectType
    {
        KEY,
        POTION
    };

    ObjectManager();
    ~ObjectManager();

    void spawnObject(ObjectType type, float x, float y);
    void updateObjects(float deltaTime, const sf::RenderWindow& window);
    void renderObjects(sf::RenderWindow& window);
    void checkObjectCollision(const Player& player);
};

#endif // OBJECTMANAGER_H