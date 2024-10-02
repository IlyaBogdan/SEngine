#include "kernel/Game.hpp"
#include "kernel/EventManager.hpp"
#include "kernel/ui/Button.hpp"

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

Game& Game::getInstance() {
    static Game game;
    return game;
}

void Game::update() {
    this->poolEvents();
}

void Game::render() {
    UI::ButtonConfig buttonConfig{10, 10, 200, 50};
    UI::Button button;
    button.draw();

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
bool Game::mouseInArea(Diapason area) {
    int mouseX = sf::Mouse::getPosition(*this->window).x;
    int mouseY = sf::Mouse::getPosition(*this->window).y;
    bool crossX = mouseX >= area.xStart && mouseX <= area.xEnd;
    bool crossY = mouseY >= area.yStart && mouseY <= area.yEnd;

    return crossX && crossY;
}
