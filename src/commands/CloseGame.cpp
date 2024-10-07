#include "commands/CloseGame.hpp"
#include "kernel/GameEngine.hpp"

using namespace Commands;

void CloseGame::execute() {
    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
    game.window->close();
}
