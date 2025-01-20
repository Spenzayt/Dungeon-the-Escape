#include "mapManager.h"
#include <iostream>

MapManager::MapManager(EnemyManager& enemyMgr, ObjectManager& objMgr)
    : enemyManager(&enemyMgr), objectManager(&objMgr) {
}

MapManager::~MapManager() {}

void MapManager::loadMap(const std::string& elementsFilename) {
    if (!elementsTexture.loadFromFile(elementsFilename)) {
        std::cerr << "Erreur de chargement de la texture des éléments: " << elementsFilename << std::endl;
        return;
    }

    elementsSprite.setTexture(elementsTexture);

    float scaleX = 1080.f / elementsTexture.getSize().x;
    float scaleY = 1080.f / elementsTexture.getSize().y;

    elementsSprite.setScale(scaleX, scaleY);
}

void MapManager::updateObjects(float deltaTime, const sf::RenderWindow& window, const Player& player) {
    if (objectManager) {
        objectManager->updateObjects(deltaTime, window);
    }

    if (enemyManager) {
        enemyManager->updateEnemies(deltaTime, player);
    }
}

void MapManager::renderObjects(sf::RenderWindow& window) {
    if (objectManager) {
        objectManager->renderObjects(window);
    }
    if (enemyManager) {
        enemyManager->renderEnemies(window);
    }
    window.draw(elementsSprite);
}
