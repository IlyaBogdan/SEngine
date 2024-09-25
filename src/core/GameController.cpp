#include "core/GameController.hpp"
#include "core/GameEngine.hpp";

using namespace Core;

GameController::GameController() {
    
}

void GameController::end() {
    Core::GameEngine& engine = Core::GameEngine::getInstance();
    engine.stop();
}
