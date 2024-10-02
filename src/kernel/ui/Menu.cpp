#include "kernel/ui/Menu.hpp"
#include "kernel/ui/Button.hpp"
#include "kernel/interfaces/IDrawable.hpp"

using namespace Kernel::UI;

void Menu::draw() {
    std::for_each(this->elements.begin(), this->elements.end(),
        [](Interfaces::IDrawable* element) {
            element->draw();
        }
    );
}