#include "kernel/GameEngine.hpp"
#include "kernel/Collider.hpp"
#include "menu/start/StartMenu.hpp"
#include "levels/HelloWorld/HelloWorld.hpp"
#include "objects/main_character/MainCharacter.hpp"
#include "objects/static/Bush.hpp"
#include <iostream>

using namespace Kernel;

//GameInstance::Menu::StartMenu menu;
GameInstance::Levels::HelloWorld helloWorld_Level;
GameInstance::Objects::MainCharacter& mainCharacter = GameInstance::Objects::MainCharacter::getInstance();
GameInstance::Objects::Bush bigBush(GameInstance::Objects::BushVariant::BIG);
GameInstance::Objects::Bush bigBush2(GameInstance::Objects::BushVariant::BIG);
GameInstance::Objects::Bush smallBush(GameInstance::Objects::BushVariant::SMALL);
GameInstance::Objects::Bush mediumBush(GameInstance::Objects::BushVariant::MEDIUM);
Collider& collider = Collider::getInstance();

GameEngine::GameEngine() {
    int windowWidth = 800;
    int windowHeight = 640;
    
    this->window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "GameEngine 1", sf::Style::Fullscreen);
    //this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "GameEngine 1", sf::Style::Close);
    this->window->setFramerateLimit(120);
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
    collider.process();
    this->poolEvents();
}

void GameEngine::render() {
    this->window->clear();
    bigBush.setCoordinate({ 450.f, 50.f });
    bigBush2.setCoordinate({ 0.f, 50.f });
    smallBush.setCoordinate({ 600.f, 50.f });
    mediumBush.setCoordinate({ 400.f, 50.f });

    helloWorld_Level.run();

    mainCharacter.draw();
    bigBush.draw();
    bigBush2.draw();
    mediumBush.draw();
    smallBush.draw();

    collider.checkCollisions();
    this->window->display();
}

void GameEngine::poolEvents() {
    while (this->window->pollEvent(this->event)) {
        //eventManager.handleEvent(event);

        if (this->event.type == sf::Event::Closed) {
            this->window->close();
        }

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
