#include "event/EventManager.hpp"

using namespace Event;

EventManager& EventManager::getInstance() {
    static EventManager eventManager;
    return eventManager;
}

void EventManager::handleEvent(Graphics::Window& context) {
    sf::Event event;
    sf::Window* sfmlWindow = context.getContext();
    while (sfmlWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) sfmlWindow->close();

        // keyboard
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) sfmlWindow->close();
        }

        // mouse
    }
}