#include "kernel/Menu.hpp"
#include "kernel/ui/Button.hpp"

using namespace Kernel;

Menu::Menu() {
    UI::Button button("Hello");
    this->elements.push_back(&button);
}

void Menu::draw(Kernel::Window& context) {
    for(UI::UIElement* element : this->elements) {
        element->draw(context);
    }
}

int Menu::setTexture(std::string texturePath) {

    return 1;
}