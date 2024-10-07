#include "kernel/GameLoop.hpp"
#include "kernel/GameEngine.hpp"
#include "kernel/EventManager.hpp"
#include "menu/start/StartMenu.hpp"
#include <iostream>

using namespace Kernel;

GameLoop::GameLoop() {

}

GameLoop::~GameLoop() {
    
}

GameLoop& GameLoop::getInstance() {
    static GameLoop gameLoop;
    return gameLoop;
}

const bool GameLoop::running() {
    return true;
}

void GameLoop::run() {

}
