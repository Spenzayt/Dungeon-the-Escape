#ifndef OBJECTMANAGER_H
#define OBJECTMANAGER_H

#include "entity.h"
#include "key.h"
#include "potion.h"
#include <vector>
#include <memory>
#include "player.h"
#include "Door.h"

class ObjectManager {
private:
    std::vector<std::shared_ptr<Entity>> objects;

public:
    enum ObjectType
    {
        KEY,
        POTION,
        DOOR
    };

    ObjectManager();
    ~ObjectManager();

    void spawnObject(ObjectType type, float x, float y);

    void spawnDoor(const sf::Vector2f& position);

    void updateObjects(float deltaTime, const sf::RenderWindow& window);

    void renderObjects(sf::RenderWindow& window);

    void checkObjectCollision(Player& player);

    void openAllDoors();

    void closeAllDoors();
};

#endif // OBJECTMANAGER_H