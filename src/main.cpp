#include "core/GameEngine.hpp"
#include "graphics/Window.hpp"

int main() {
    Core::GameEngine engine = Core::GameEngine();
    engine.init();
    engine.run();
    return 0;
}