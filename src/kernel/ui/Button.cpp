#include "kernel/ui/Button.hpp"
#include "kernel/Game.hpp"
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
}

void Button::draw() {
    sf::RectangleShape button;
    int marginX = 10, marginY = 10, width = 200, height = 50;

    button.setPosition(sf::Vector2f(marginX, marginY));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Red);
    button.setOutlineColor(sf::Color::Green);
    button.setOutlineThickness(1.f);

    Kernel::Game& game = Kernel::Game::getInstance();

    if (this->mouseOnElement()) {
        button.setFillColor(sf::Color::Green);
        button.setOutlineColor(sf::Color::Cyan);
    }

    game.window->draw(button);
}
