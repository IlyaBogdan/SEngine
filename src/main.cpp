#include "core/GameEngine.hpp"

int main() {
    Core::GameEngine& engine = Core::GameEngine::getInstance();
    engine.init();
    engine.run();
    return 0;
}