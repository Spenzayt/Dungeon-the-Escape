#ifndef MAPMANAGER_H
#define MAPMANAGER_H

#include <SFML/Graphics.hpp>
#include "key.h"
#include "potion.h"
#include "chaserEnemy.h"
#include "patrollingEnemy.h"
#include "enemyManager.h"
#include "objectManager.h"
#include <vector>
#include <memory>

class MapManager {
private:
    sf::Texture elementsTexture;
    sf::Sprite elementsSprite;

    std::vector<std::shared_ptr<Entity>> objects;
    EnemyManager* enemyManager;
    ObjectManager* objectManager;

public:
    MapManager(EnemyManager& enemyMgr, ObjectManager& objMgr);
    ~MapManager();

    void loadMap(const std::string& elementsFilename);
    void updateObjects(float deltaTime, const sf::RenderWindow& window, const Player& player);
    void renderObjects(sf::RenderWindow& window);
};

#endif // MAPMANAGER_H