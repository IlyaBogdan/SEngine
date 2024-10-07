#include "menu/start/elements/ExitButton.hpp"
#include "commands/CloseGame.hpp"

using namespace GameInstance::Menu::Elements;

void ExitButton::onClick() {
    (Commands::CloseGame()).execute();
}
