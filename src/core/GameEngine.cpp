#include "core/GameEngine.hpp"
#include "core/GameLoop.hpp"
#include "graphics/Window.hpp"
#include <iostream>

using namespace Core;

GameEngine::~GameEngine() {

}

bool GameEngine::init() {
    //try
    //{
        this->running = true;
        //this->loop = GameLoop::init();
        return true;
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}
}

void GameEngine::run() {
    Graphics::Window& window = Graphics::Window::Instance();
    //window.setFullscreen(true);
    //window.setFPS(60);

    while (this->running) {
        sf::Event event;
        while (window.getEvent(event)) {
            switch (event.type) {
                
                case sf::Event::Closed:
                    window.close();
                    break;

                // key pressed
                case sf::Event::KeyPressed:
                    
                    break;

                // we don't process other types of events
                default:
                    break;
            }
        }

        window.render();
    }
}

void GameEngine::stop() {

}
