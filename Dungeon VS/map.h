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

    ObjectManager objectManager;
    EnemyManager enemyManager;

    std::vector<sf::Sprite> rockSprites;
public:
    Map();
    ~Map();

    void loadFromImageFile(const std::string& elementsFilename, const sf::RenderWindow& window);
    void loadBackgroundFromImageFile(const std::string& elementsFilename, const std::string& rockTextureFile);
    void update(float deltaTime, const sf::RenderWindow& window, const Player& player);
    void draw(sf::RenderWindow& window);
};

#endif // MAP_H