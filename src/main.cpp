#include "Kernel/Engine.hpp"

int main() {
    Kernel::Engine engine = Kernel::Engine();
    while (true) {
        if (engine.mainLoop()) {
            break;
        }
    }

    return 0;
}