#include "gameOver.h"

GameOver::GameOver(float windowWidth, float windowHeight) {
    if (!font.loadFromFile("assets/fonts/Bruce Forever.ttf")) {
        std::cerr << "Erreur lors du chargement de la police." << std::endl;
    }

    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(80);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setStyle(sf::Text::Bold);
    gameOverText.setPosition(
        windowWidth / 2.f - gameOverText.getGlobalBounds().width / 2.f,
        windowHeight / 3.f
    );
}

GameOver::~GameOver() {}

void GameOver::render(sf::RenderWindow& window) {
    window.draw(gameOverText);
}