#include "kernel/ui/Button.hpp"

using namespace Kernel::UI;

Button::Button(std::string text) {
    this->text = text;  
    this->width = 100;
    this->height = 50;
}

void Button::draw(Kernel::Window& context) {
    sf::RectangleShape rectangle;

    rectangle.setPosition(this->width, this->height);
    rectangle.setSize(sf::Vector2f(this->width, this->height));
    rectangle.setFillColor(sf::Color::Cyan);
    rectangle.setOutlineColor(sf::Color::Red);
    rectangle.setOutlineThickness(1.f);

    sf::Text text;

    text.setString(this->text);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    context.getContext()->draw(rectangle);
}

