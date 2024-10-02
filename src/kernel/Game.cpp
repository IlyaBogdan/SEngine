#include "kernel/Game.hpp"
#include "kernel/EventManager.hpp"

using namespace Kernel;

EventManager& eventManager = EventManager::getInstance();

Game::Game() {
    int windowWidth = 800;
    int windowHeight = 640;

    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Game 1", sf::Style::Close);
}

Game::~Game() {
    delete this->window;
}

const bool Game::running() {
    return this->window->isOpen();
}

Game& Game::init() {
    static Game game;
    return game;
}

void Game::update() {
    this->poolEvents();
}

void Game::render() {
    this->window->display();
}

void Game::poolEvents() {
    while (this->window->pollEvent(this->event)) {
        //eventManager.handleEvent(event);

        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }

        // keyboard
        if (this->event.type == sf::Event::KeyPressed) {
            if (this->event.key.code == sf::Keyboard::Escape)  {
                this->window->close();
            }

            if (this->event.key.code == sf::Keyboard::D) {
                //mainCharacter.moveTo(Interfaces::Direction::RIGHT);
            }

            if (this->event.key.code == sf::Keyboard::A) {
                //mainCharacter.moveTo(Interfaces::Direction::LEFT);
            }

            if (this->event.key.code == sf::Keyboard::Space) {
                //mainCharacter.jump();
            }
        }

        if (this->event.type == sf::Event::KeyReleased) {

            if (this->event.key.code == sf::Keyboard::D) {
                //mainCharacter.stop();
            }

            if (this->event.key.code == sf::Keyboard::A) {
                //mainCharacter.stop();
            }
        }
    }
}

void Game::loop() {

    while (this->running()) {
        this->update();
        this->render();
    }
}