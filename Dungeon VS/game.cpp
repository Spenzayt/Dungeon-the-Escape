#include "Game.h"

Game::Game()
    : isRunning(false), isGameOver(false), gameOver(1920, 1080),
    enemyManager(), objectManager() {
    srand(static_cast<unsigned int>(time(0)));
    createWindow();
    player.setMap(&map);
    map.loadBackgroundFromImageFile("assets/map/background.png", "assets/map/rock.png");
    map.loadFromImageFile("assets/map/objects.png", window, player);
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
    if (isGameOver) return;

    player.update(deltaTime, window);
    enemyManager.updateEnemies(deltaTime, player);
    map.update(deltaTime, window, player);

    if (player.isDead()) {
        isGameOver = true;
    }
}

void Game::render() {
    window.clear(sf::Color(135, 206, 235));

    if (isGameOver) {
        gameOver.render(window);
    }
    else {
        map.draw(window);
        player.draw(window);
        enemyManager.renderEnemies(window);
    }

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