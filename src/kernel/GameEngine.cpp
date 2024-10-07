#include "kernel/GameEngine.hpp"
#include "menu/start/StartMenu.hpp"
#include "levels/HelloWorld/HelloWorld.hpp"
#include "objects/main_character/MainCharacter.hpp"
#include <iostream>

using namespace Kernel;

//GameInstance::Menu::StartMenu menu;
GameInstance::Levels::HelloWorld helloWorld_Level;
GameInstance::Objects::MainCharacter mainCharacter;

GameEngine::GameEngine() {
    int windowWidth = 800;
    int windowHeight = 640;

    this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "GameEngine 1", sf::Style::Close);
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
    //helloWorld_Level.run();
    this->window->clear();
    
    mainCharacter.draw();

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
            if (eventHandlers.handlerDefined(eventHandlers.keyboardEventHandlers.handlers_pressed, this->event.key.code)) {
                eventHandlers.keyboardEventHandlers.handlers_pressed[this->event.key.code]();
            }
        }

        if (this->event.type == sf::Event::KeyReleased) {
            if (eventHandlers.handlerDefined(eventHandlers.keyboardEventHandlers.handlers_released, this->event.key.code)) {
                eventHandlers.keyboardEventHandlers.handlers_released[this->event.key.code]();
            }
        }

        // mouse

        if (this->event.type == sf::Event::MouseButtonPressed) {
            if (eventHandlers.handlerDefined(eventHandlers.mouseEventHandlers.handlers_pressed, this->event.key.code)) {
                eventHandlers.mouseEventHandlers.handlers_pressed[this->event.key.code]();
            }
        }

        if (this->event.type == sf::Event::MouseButtonReleased) {
            if (eventHandlers.handlerDefined(eventHandlers.mouseEventHandlers.handlers_released, this->event.key.code)) {
                eventHandlers.mouseEventHandlers.handlers_released[this->event.key.code]();
            }
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
