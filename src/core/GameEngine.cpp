#include "core/GameEngine.hpp"
#include "core/GameLoop.hpp"
#include "graphics/Window.hpp"
#include <iostream>

using namespace Core;

bool GameEngine::init() {
    //try
    //{
        this->running = true;
        //this->loop = GameLoop::init();
        this->inputManager = &(Input::InputManager());
        return true;
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}
}

void GameEngine::run() {
    Graphics::Window& window = Graphics::Window::Instance();
    window.setFullscreen(true);
    window.setFPS(60);

    while (this->running) {
        sf::Event event;
        while (window.getEvent(&event)) {
            this->inputManager->handleEvent(&event, window.getContext());
        }

        window.render();
    }
}

void GameEngine::stop() {
    this->running = false;
}
