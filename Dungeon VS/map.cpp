#include "map.h"
#include <iostream>

Map::Map() {}

Map::~Map() {}

void Map::loadFromImageFile(const std::string& elementsFilename, const sf::RenderWindow& window, Player& player) {
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
                objectManager.spawnObject(ObjectManager::KEY, x * 60.f, y * 60.f, &player);
            }
            else if (pixelColor == sf::Color(217, 0, 255)) {
                objectManager.spawnObject(ObjectManager::POTION, x * 60.f, y * 60.f, &player);
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
            else if (pixelColor == sf::Color(255, 225, 0)) {
                sf::Vector2f doorPosition(x * 60.f - 60.f, y * 60.f);
                objectManager.spawnDoor(doorPosition);
                sf::Texture doorTexture;
                sf::Sprite door(doorTexture);
                door.setColor(sf::Color::Red);
                door.setPosition(doorPosition);
                door.setScale(2.f, 2.f);
                doorSprites.push_back(door);
            }
        }
    }
}

void Map::update(float deltaTime, const sf::RenderWindow& window, Player& player) {
    objectManager.updateObjects(deltaTime, window);
    enemyManager.updateEnemies(deltaTime, player);
    objectManager.checkObjectCollision(player);

    sf::FloatRect playerBounds(player.getPosX(), player.getPosY(), player.getPlayerSprite().getSize().x, player.getPlayerSprite().getSize().y);
    if (checkWallCollision(playerBounds)) {
        std::cout << "Collision avec le mur !" << std::endl;
    }
}

void Map::draw(sf::RenderWindow& window) {
    for (auto& rock : rockSprites) {
        window.draw(rock);
    }

    objectManager.renderObjects(window);
    enemyManager.renderEnemies(window);
}

bool Map::checkWallCollision(const sf::FloatRect& objectBounds) {
    for (auto& rock : rockSprites) {
        if (rock.getGlobalBounds().intersects(objectBounds)) {
            return true;
        }
    }

    for (auto& door : doorSprites) {
        if (door.getGlobalBounds().intersects(objectBounds)) {
            return true;
        }
    }

    return false;
}