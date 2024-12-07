#include "SDL.h"
#include "Kernel/Engine.hpp"

void drawWindow() {
    SDL_Log("%s", "Hello world!");
}

int main() {
    drawWindow();
    Kernel::Engine engine = Kernel::Engine();
    while (true) {
        if (engine.mainLoop()) {
            break;
        }
    }

    return 0;
}