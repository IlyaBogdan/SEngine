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

// Kernel::MouseHandlerMap mouseHandlerMap;
//     mouseHandlerMap.handlers_pressed = {
//         { sf::Mouse::Left, [this]() {
//             std::cout << "Left click working" << std::endl;
//         }},
//         { sf::Mouse::Right, []() {
//             Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
//             game.window->close();
//             std::cout << "Right click working" << std::endl;
//         }},
//     };

//     mouseHandlerMap.handlers_released = {
//         { sf::Mouse::Left, [this]() {
//             std::cout << "Left click release" << std::endl;
//         }},
//         { sf::Mouse::Right, [this]() {
//             std::cout << "Right click release" << std::endl;
//         }},
//     };
//     Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
//     game.setMouseHandlers(mouseHandlerMap);

void Kernel::UI::Menu::onClick() {
    
}
