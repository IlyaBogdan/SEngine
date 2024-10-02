#include "kernel/Game.hpp"

Kernel::Game& game = Kernel::Game::init();

int main() {
    game.loop();

    return 0;
}