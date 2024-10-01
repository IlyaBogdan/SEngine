#include "kernel/Game.hpp"

Kernel::Game game = Kernel::Game();

int main() {
    game.init();
    game.loop();

    return 0;
}