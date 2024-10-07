#include "kernel/ui/Menu.hpp"
#include "kernel/ui/Button.hpp"
#include "kernel/interfaces/IDrawable.hpp"
#include "kernel/interfaces/IClickable.hpp"
#include "kernel/GameEngine.hpp"
#include <iostream>

using namespace Kernel::UI;

Menu::~Menu() {
    
}

void Menu::draw() {
    std::for_each(this->elements.begin(), this->elements.end(),
        [](Interfaces::IDrawable* element) {
            element->draw();
        }
    );
    GameEngine& game = GameEngine::getInstance();

    MouseHandlerMap menuMouseHandlers;
    EventHandlerMap handlers_pressed {
        { sf::Mouse::Left, [this]() {
            if (this->elements.size()) {
                std::for_each(this->elements.begin(), this->elements.end(),
                    [](Kernel::UIElement* element) {
                        if (element->mouseOnElement()) {
                            element->onClick();
                        }
                    }
                );
            } else {
                GameEngine& game = GameEngine::getInstance();
                game.window->close();
            }
        }}
    };

    menuMouseHandlers.handlers_pressed = handlers_pressed;
    game.setMouseHandlers(menuMouseHandlers);

    this->onClick();
}

void Kernel::UI::Menu::onClick() {
    
}
