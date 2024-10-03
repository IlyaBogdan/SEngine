#include "kernel/GameEngine.hpp"
#include "kernel/EventManager.hpp"
#include "menu/start/StartMenu.hpp"
#include <iostream>

using namespace Kernel;

EventManager& eventManager = EventManager::getInstance();

GameEngine::GameEngine() {
    int windowWidth = 800;
    int windowHeight = 640;
    this->initKeyboardHandlers();

    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "GameEngine 1", sf::Style::Close);
}

void GameEngine::initKeyboardHandlers() {
    EventHandlers eventHandlers;

    KeyboardHandlerMap keyboardHandlers;

    keyboardHandlers.handlers_pressed = {
        { sf::Keyboard::Escape, [this]() { this->window->close(); }},
        { sf::Keyboard::D, [this]() { this->window->close(); }},
        { sf::Keyboard::A, [this]() { this->window->close(); }},
        { sf::Keyboard::Space, [this]() { this->window->close(); }},
    };

    keyboardHandlers.handlers_released = {
        { sf::Keyboard::D, [this]() { this->window->close(); }},
        { sf::Keyboard::A, [this]() { this->window->close(); }},
    };

    eventHandlers.keyboardEventHandlers = keyboardHandlers;

    MouseHandlerMap mouseHandlerMap;
    mouseHandlerMap.handlers_pressed = {
        { sf::Mouse::Left, [this]() { this->window->close(); }},
        { sf::Mouse::Right, [this]() { this->window->close(); }},
    };

    mouseHandlerMap.handlers_released = {
        { sf::Mouse::Left, [this]() {

        }},
        { sf::Mouse::Right, [this]() {

        }},
    };

    eventHandlers.mouseEventHandlers = mouseHandlerMap;

    this->eventHandlers = eventHandlers;
}

GameEngine::~GameEngine() {
    delete this->window;
}

GameEngine* GameEngine::setMouseHandlers(MouseHandlerMap mouseHandlers) {
    this->eventHandlers.mouseEventHandlers = mouseHandlers;
    return this;
}

GameEngine* GameEngine::setKeyboardHandlers(KeyboardHandlerMap keyboardHandlers) {
    this->eventHandlers.keyboardEventHandlers = keyboardHandlers;
    return this;
}

const bool GameEngine::running() {
    return this->window->isOpen();
}

GameEngine& GameEngine::getInstance() {
    static GameEngine game;
    return game;
}

void GameEngine::update() {
    this->poolEvents();
}

void GameEngine::render() {
    GameInstance::Menu::StartMenu menu;
    menu.draw();

    this->window->display();
}

void GameEngine::poolEvents() {
    while (this->window->pollEvent(this->event)) {
        //eventManager.handleEvent(event);

        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }

        // keyboard
        if (this->event.type == sf::Event::KeyPressed) {
            eventHandlers.keyboardEventHandlers.handlers_pressed[this->event.key.code]();
        }

        if (this->event.type == sf::Event::KeyReleased) {
            eventHandlers.keyboardEventHandlers.handlers_released[this->event.key.code]();
        }

        // mouse

        if (this->event.type == sf::Event::MouseButtonPressed) {
            eventHandlers.mouseEventHandlers.handlers_pressed[this->event.key.code]();
        }

        if (this->event.type == sf::Event::MouseButtonReleased) {
            eventHandlers.mouseEventHandlers.handlers_released[this->event.key.code]();
        }
    }
}

void GameEngine::loop() {

    while (this->running()) {
        this->update();
        this->render();
    }
}
bool GameEngine::mouseInArea(Diapason area) {
    int mouseX = sf::Mouse::getPosition(*this->window).x;
    int mouseY = sf::Mouse::getPosition(*this->window).y;
    bool crossX = mouseX >= area.xStart && mouseX <= area.xEnd;
    bool crossY = mouseY >= area.yStart && mouseY <= area.yEnd;

    return crossX && crossY;
}
