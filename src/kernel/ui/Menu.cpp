#include "kernel/ui/Menu.hpp"
#include "kernel/ui/Button.hpp"
#include "kernel/interfaces/IDrawable.hpp"

using namespace Kernel::UI;

Menu::Menu() {
    ButtonConfig buttonConfig;
    buttonConfig.x = 10;
    buttonConfig.y = 10;
    buttonConfig.width = 200;
    buttonConfig.height = 50;

    UITextConfig textConfig;
    textConfig.color = sf::Color::White;
    textConfig.fontSize = 20;
    textConfig.style = sf::Text::Bold;
    textConfig.text = "Hello, Username!";

    buttonConfig.text = textConfig;

    Button* button = new Button(buttonConfig);
    this->elements.push_back(button);
}

Menu::~Menu() {
    
}

void Menu::draw() {
    std::for_each(this->elements.begin(), this->elements.end(),
        [](Interfaces::IDrawable* element) {
            element->draw();
        }
    );
}