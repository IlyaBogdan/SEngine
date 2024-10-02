#include "kernel/Game.hpp"

Kernel::Game& game = Kernel::Game::getInstance();

int main() {
    game.loop();

    return 0;
}