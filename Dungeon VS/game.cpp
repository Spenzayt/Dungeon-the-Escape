#include "Game.h"

Game::Game() : isRunning(false) {
    createWindow();
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
}

void Game::render() {
    window.clear();
    player.draw(window);
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