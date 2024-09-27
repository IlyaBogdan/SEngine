#include "event/EventManager.hpp"

using namespace Event;

EventManager& EventManager::getInstance() {
    static EventManager eventManager;
    return eventManager;
}

void EventManager::handleEvent(sf::Window* context) {
    sf::Event event;
    while (context->pollEvent(event)) {
        if (event.type == sf::Event::Closed) context->close();

        // keyboard
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) context->close();
        }

        // mouse
    }
}