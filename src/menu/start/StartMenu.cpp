#include "kernel/GameEngine.hpp"
#include "menu/shared/MenuButton.hpp"
#include "menu/start/StartMenu.hpp"
#include <iostream>

using namespace GameInstance::Menu;

Elements::MenuButton* startButton() {
    Kernel::UI::ButtonConfig buttonConfig;
    buttonConfig.x = 10;
    buttonConfig.y = 10;
    buttonConfig.width = 200;
    buttonConfig.height = 50;

    Kernel::UITextConfig textConfig;
    textConfig.color = sf::Color::White;
    textConfig.fontSize = 20;
    textConfig.style = sf::Text::Bold;
    textConfig.text = "Start";

    buttonConfig.text = textConfig;

    Elements::MenuButton* button = new Elements::MenuButton(buttonConfig);
    return button;
}

Elements::MenuButton* exitButton() {
    Kernel::UI::ButtonConfig buttonConfig;
    buttonConfig.x = 10;
    buttonConfig.y = 80;
    buttonConfig.width = 200;
    buttonConfig.height = 50;

    Kernel::UITextConfig textConfig;
    textConfig.color = sf::Color::White;
    textConfig.fontSize = 20;
    textConfig.style = sf::Text::Bold;
    textConfig.text = "Exit";

    buttonConfig.text = textConfig;

    Elements::MenuButton* button = new Elements::MenuButton(buttonConfig);
    return button;
}


StartMenu::StartMenu() {
    Kernel::UI::Button* startBtn = startButton();
    Kernel::UI::Button* exitBtn = exitButton();

    this->elements.push_back(startBtn);
    this->elements.push_back(exitBtn);

    Kernel::MouseHandlerMap mouseHandlerMap;
    mouseHandlerMap.handlers_pressed = {
        { sf::Mouse::Left, [this]() {
            std::cout << "Left click working" << std::endl;
        }},
        { sf::Mouse::Right, []() {
            Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
            game.window->close();
            std::cout << "Right click working" << std::endl;
        }},
    };

    mouseHandlerMap.handlers_released = {
        { sf::Mouse::Left, [this]() {
            std::cout << "Left click release" << std::endl;
        }},
        { sf::Mouse::Right, [this]() {
            std::cout << "Right click release" << std::endl;
        }},
    };
    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
    game.setMouseHandlers(mouseHandlerMap);
}

void StartMenu::handleClick() {
    
}