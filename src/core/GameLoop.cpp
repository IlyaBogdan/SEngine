#include "core/GameLoop.hpp"

using namespace Core;

GameLoop::GameLoop() {
    
}

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

