#include "kernel/GameEngine.hpp"

Kernel::GameEngine& game = Kernel::GameEngine::getInstance();

int main() {
    game.loop();

    return 0;
}