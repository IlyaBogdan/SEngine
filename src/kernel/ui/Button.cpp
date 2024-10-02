#include "kernel/ui/Button.hpp"
#include "kernel/GameEngine.hpp"
#include "SFML/Graphics.hpp"

using namespace Kernel::UI;

Button::Button() {
    this->width = 150;
    this->height = 50;
    this->x = 10;
    this->y = 10;
}

Button::Button(ButtonConfig config) {
    this->width = config.width;
    this->height = config.height;
    this->x = config.x;
    this->y = config.y;
    this->text = config.text;
}

void Button::renderText() {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("recources/fonts/arial.ttf");
    text.setFont(font);
    text.setString(this->text.text);
    text.setCharacterSize(this->text.fontSize);
    text.setFillColor(this->text.color);
    text.setStyle(this->text.style);
    
    int textHeight = text.getLocalBounds().height;
    int textWidth = text.getLocalBounds().width;

    int yMargin = this->y + ((this->height - textHeight) / 2);
    int xMargin = this->x + ((this->width - textWidth) / 2);

    text.setPosition(sf::Vector2f(xMargin, yMargin));

    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
    game.window->draw(text);
}

void Button::draw() {
    sf::RectangleShape button;

    button.setPosition(sf::Vector2f(this->x, this->y));
    button.setSize(sf::Vector2f(this->width, this->height));
    button.setFillColor(sf::Color::Red);
    button.setOutlineColor(sf::Color::Green);
    button.setOutlineThickness(1.f);

    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();

    if (this->mouseOnElement()) {
        button.setFillColor(sf::Color::Green);
        button.setOutlineColor(sf::Color::Cyan);
    }

    game.window->draw(button);
    this->renderText();
}
