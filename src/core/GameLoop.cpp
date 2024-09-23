#include "core/GameLoop.hpp"

GameLoop GameLoop::init() {
    GameLoop loop = GameLoop();

    return loop;
}

void GameLoop::run() {
    this->running = true;
}

void GameLoop::stop(){
    this->running = false;
}

