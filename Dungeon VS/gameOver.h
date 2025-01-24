#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameOver {
private:
    sf::Font font;
    sf::Text gameOverText;

public:
    GameOver(float windowWidth, float windowHeight);
    ~GameOver();

    void render(sf::RenderWindow& window);
};

#endif // GAMEOVER_H