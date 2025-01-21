#include "map.h"
#include <iostream>

Map::Map() {}

Map::~Map() {}

void Map::loadFromImageFile(const std::string& elementsFilename, const sf::RenderWindow& window) {
    if (!image.loadFromFile(elementsFilename)) {
        std::cerr << "Erreur de chargement de l'image: " << elementsFilename << std::endl;
        return;
    }

    for (unsigned int x = 0; x < image.getSize().x; x++) {
        for (unsigned int y = 0; y < image.getSize().y; y++) {
            sf::Color pixelColor = image.getPixel(x, y);

            if (pixelColor == sf::Color(255, 0, 0)) {
                enemyManager.spawnEnemy(1, EnemyManager::CHASER, x * 60.f, y * 60.f);
            }
            else if (pixelColor == sf::Color(15, 255, 0)) {
                enemyManager.spawnEnemy(1, EnemyManager::PATROLLING, x * 60.f, y * 60.f);
            }
            else if (pixelColor == sf::Color(251, 255, 0)) {
                objectManager.spawnObject(ObjectManager::KEY, x * 60.f, y * 60.f);
            }
            else if (pixelColor == sf::Color(217, 0, 255)) {
                objectManager.spawnObject(ObjectManager::POTION, x * 60.f, y * 60.f);
            }
        }
    }
}

void Map::loadBackgroundFromImageFile(const std::string& elementsFilename, const std::string& rockTextureFile) {
    if (!background.loadFromFile(elementsFilename)) {
        std::cerr << "Erreur de chargement de l'image: " << elementsFilename << std::endl;
        return;
    }

    if (!rockTexture.loadFromFile(rockTextureFile)) {
        std::cerr << "Erreur de chargement de la texture du rocher: " << rockTextureFile << std::endl;
        return;
    }

    float rockScaleX = 60.f / rockTexture.getSize().x;
    float rockScaleY = 60.f / rockTexture.getSize().y;

    for (unsigned int x = 0; x < background.getSize().x; x++) {
        for (unsigned int y = 0; y < background.getSize().y; y++) {
            sf::Color pixelColor = background.getPixel(x, y);

            if (pixelColor == sf::Color::Black) {
                sf::Sprite rock(rockTexture);
                rock.setScale(rockScaleX, rockScaleX);
                rock.setPosition(x * 60.f, y * 60.f);
                rockSprites.push_back(rock);
            }
            else if (pixelColor == sf::Color::White) {
                // Ajouter d'autres �l�ments si n�cessaire (par exemple, des plateformes ou objets)
            }
        }
    }
}

void Map::update(float deltaTime, const sf::RenderWindow& window, const Player& player) {
    objectManager.updateObjects(deltaTime, window);
    enemyManager.updateEnemies(deltaTime, player);
    objectManager.checkObjectCollision(player);
}

void Map::draw(sf::RenderWindow& window) {
    for (auto& rock : rockSprites) {
        window.draw(rock);
    }

    objectManager.renderObjects(window);
    enemyManager.renderEnemies(window);
}