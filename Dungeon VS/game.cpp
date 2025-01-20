#include "Game.h"

Game::Game() : isRunning(false), enemyManager(), objectManager(), mapManager(enemyManager, objectManager) {
    srand(static_cast<unsigned int>(time(0)));
    createWindow();
    mapManager.loadMap("assets/map/elements.png");
}

Game::~Game() {}

void Game::createWindow() {
    window.create(sf::VideoMode(), "Dungeon the Escape", sf::Style::Fullscreen);
    window.setFramerateLimit(60);
    isRunning = true;
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            isRunning = false;
        }
    }
}

void Game::update(float deltaTime) {
    player.update(deltaTime, window);
    enemyManager.updateEnemies(deltaTime, player);
    mapManager.updateObjects(deltaTime, window, player);
}

void Game::render() {
    window.clear();
    player.draw(window);
    enemyManager.renderEnemies(window);
    mapManager.renderObjects(window);
    window.display();
}

void Game::run() {
    sf::Clock clock;

    while (isRunning) {
        processEvents();
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);
        render();
    }
}