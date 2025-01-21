#include "objectManager.h"

ObjectManager::ObjectManager() {}

ObjectManager::~ObjectManager() {}

void ObjectManager::spawnObject(ObjectType type, float x, float y) {
    std::shared_ptr<Entity> newObject;

    switch (type) {
    case KEY:
        newObject = std::make_shared<Key>(x, y);
        break;
    case POTION:
        objects.push_back(std::make_shared<Potion>(x, y));
        break;
    default:
        break;
    }

    if (newObject) {
        objects.push_back(newObject);
    }
}

void ObjectManager::updateObjects(float deltaTime, const sf::RenderWindow& window) {
    for (auto& object : objects) {
        object->update(deltaTime, window);
    }
}

void ObjectManager::renderObjects(sf::RenderWindow& window) {
    for (auto& object : objects) {
        object->draw(window);
    }
}

void ObjectManager::checkObjectCollision(const Player& player) {
    for (auto& object : objects) {
        if (auto key = dynamic_cast<Key*>(object.get())) {
            if (key->getBounds().intersects(player.getPlayerSprite().getGlobalBounds()) && !key->isKeyCollected()) {
                key->collectKey();
            }
        }
        else if (auto potion = dynamic_cast<Potion*>(object.get())) {
            if (potion->getBounds().intersects(player.getPlayerSprite().getGlobalBounds()) && !potion->isPotionCollected()) {
                potion->collectPotion();
            }
        }
    }
}