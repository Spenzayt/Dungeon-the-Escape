#include "objectManager.h"
#include <iostream>

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
    case DOOR:
        std::cerr << "Erreur : Utilisez la surcharge de `spawnObject` pour les portes avec textures." << std::endl;
        return;
    default:
        break;
    }

    if (newObject) {
        objects.push_back(newObject);
    }
}

void ObjectManager::spawnDoor(const sf::Vector2f& position) {
    objects.push_back(std::make_shared<Door>(position));
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

void ObjectManager::checkObjectCollision(Player& player) {
    for (auto it = objects.begin(); it != objects.end();) {
        auto object = *it;

        if (auto key = dynamic_cast<Key*>(object.get())) {
            if (key->getBounds().intersects(player.getPlayerSprite().getGlobalBounds()) && !key->isKeyCollected()) {
                key->collectKey();
                player.setHasKey(true);
                std::cout << "Clé ramassée !" << std::endl;
                it = objects.erase(it);
                continue;
            }
        }
        else if (auto potion = dynamic_cast<Potion*>(object.get())) {
            if (potion->getBounds().intersects(player.getPlayerSprite().getGlobalBounds()) && !potion->isPotionCollected()) {
                potion->collectPotion();
                std::cout << "Potion ramassée !" << std::endl;
                it = objects.erase(it);
                continue;
            }
        }
        else if (auto door = dynamic_cast<Door*>(object.get())) {
            if (door->getBounds().intersects(player.getPlayerSprite().getGlobalBounds()) && !door->isOpen()) {
                if (player.getHasKey()) {
                    door->open();
                    std::cout << "Porte ouverte !" << std::endl;
                }
                else {
                    std::cout << "Vous avez besoin d'une clé pour ouvrir cette porte." << std::endl;
                }
            }
        }
        ++it;
    }
}