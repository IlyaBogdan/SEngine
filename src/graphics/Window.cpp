#include "graphics/Window.hpp"

using namespace Graphics;

Window& Window::getInstance() {
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

sf::RenderWindow* Window::getContext() {
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
    int style = this->fullscreen ? sf::Style::Fullscreen : sf::Style::Close;
    if (this->context) {
        delete this->context;
    }
    this->context = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Hello world!", style);
}
