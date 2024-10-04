#include "kernel/GameEngine.hpp"
#include "menu/start/elements/ExitButton.hpp"

using namespace GameInstance::Menu::Elements;

void ExitButton::onClick() {
    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
    game.window->close();
}
