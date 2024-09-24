#include "core/GameEngine.hpp"

int main() {
    Core::GameEngine engine = Core::GameEngine();
    engine.init();
    engine.run();
    return 0;
}