#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "graphics/Window.hpp"

using namespace Graphics;

void Window::render() {
    sf::Window window(sf::VideoMode(640, 480), "Hello world!");
}