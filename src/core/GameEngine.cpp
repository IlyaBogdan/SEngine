#include "core/GameEngine.hpp"
#include "core/GameLoop.hpp"
#include "input/InputAdapter.hpp"
#include "input/controlls/InputEvent.hpp"
#include "graphics/Window.hpp"
#include <iostream>

using namespace Core;

GameEngine::~GameEngine() {
    delete inputManager;
}

bool GameEngine::init() {
    //try
    //{
        this->running = true;
        //this->loop = GameLoop::init();
        this->inputManager = InputModule::InputAdapter::getInputManager();
        return true;
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}
}

void GameEngine::run() {
    Graphics::Window& window = Graphics::Window::Instance();
    while (this->running) {
        this->inputManager->handleInput();
        InputModule::InputEvent* event = this->inputManager->getEvent();

        if (event) {
            std::cout << event->eventType << "\n";
            std::cout << event->controller << "\n";
            std::cout << "================\n";
        }

        window.render();       
    }
}

void GameEngine::stop() {

}
