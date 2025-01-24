#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include "objectManager.h"
#include "enemyManager.h"

class Map {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Image image;

    sf::Image background;

    sf::Texture rockTexture;
    sf::Sprite rockSprite;

    sf::Texture openDoorTexture;
    sf::Texture closeDoorTexture;

    ObjectManager objectManager;
    EnemyManager enemyManager;

    std::vector<sf::Sprite> rockSprites;
    std::vector<sf::Sprite> doorSprites;

public:
    Map();
    ~Map();

    void loadFromImageFile(const std::string& elementsFilename, const sf::RenderWindow& window, Player& player);
    void loadBackgroundFromImageFile(const std::string& elementsFilename, const std::string& rockTextureFile);
    void update(float deltaTime, const sf::RenderWindow& window, Player& player);
    void draw(sf::RenderWindow& window);

    bool checkWallCollision(const sf::FloatRect& objectBounds);
};

#endif // MAP_H