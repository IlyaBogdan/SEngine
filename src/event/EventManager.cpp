#include "event/EventManager.hpp"
#include "objects/game/character/MainCharacter.hpp"

using namespace Event;

EventManager& EventManager::getInstance() {
    static EventManager eventManager;
    return eventManager;
}

void EventManager::handleEvent(Graphics::Window& context) {
    sf::Event event;
    sf::Window* sfmlWindow = context.getContext();
    Character::MainCharacter& mainCharacter = Character::MainCharacter::getInstance();

    while (sfmlWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) sfmlWindow->close();

        // keyboard
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) sfmlWindow->close();

            if (event.key.code == sf::Keyboard::D) {
                mainCharacter.moveTo(GameObjectInterface::Direction::RIGHT);
            }

            if (event.key.code == sf::Keyboard::A) {
                mainCharacter.moveTo(GameObjectInterface::Direction::LEFT);
            }
        }

        if (event.type == sf::Event::KeyReleased) {

            if (event.key.code == sf::Keyboard::D) {
                mainCharacter.stop();
            }

            if (event.key.code == sf::Keyboard::A) {
                mainCharacter.stop();
            }
        }

        // mouse
    }
}