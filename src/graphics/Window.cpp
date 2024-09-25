#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "graphics/Window.hpp"

using namespace Graphics;

Window& Window::Instance() {
    static Window window;
    return window;
}

Window::Window() {
    this->applySettings();
}

void Window::render() {
    this->context->display();
}

void Window::close() {
    this->context->close();
}

sf::Window* Window::getContext() {
    return this->context;
}

bool Window::getEvent(sf::Event *event) {
    return this->context->pollEvent(*(event));
}

Window* Window::setFullscreen(bool fullscreen) {
    this->fullscreen = fullscreen;
    this->applySettings();
    return this;
}

Window* Window::setFPS(int fps) {
    this->fps = fps;
    this->applySettings();
    return this;
}

void Window::applySettings() {
    sf::VideoMode videoMode = this->fullscreen ? sf::VideoMode::getDesktopMode() : sf::VideoMode(640, 480);
    int style = this->fullscreen ? sf::Style::Fullscreen : sf::Style::Close;
    if (this->context) {
        delete this->context;
    }
    
    this->context = new sf::Window(videoMode, "Hello world!", this->fullscreen);
    this->context->setFramerateLimit(this->fps);
}
