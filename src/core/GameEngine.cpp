#include "core/GameEngine.hpp"
#include "input/InputAdapter.hpp"

bool GameEngine::init() {
    //try
    //{
        this->running = true;
        this->loop = GameLoop::init();
        this->inputManager = InputAdapter::getInputManager();
        return true;
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}
}

void GameEngine::run() {
    while (this->running) {
        this->inputManager->getInputState();
    }
}

void GameEngine::stop() {

}
