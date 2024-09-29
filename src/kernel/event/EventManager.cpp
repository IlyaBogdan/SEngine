#include "kernel/event/EventManager.hpp"
#include "objects/game/character/MainCharacter.hpp"

using namespace Kernel;

EventManager& EventManager::getInstance() {
    static EventManager eventManager;
    return eventManager;
}

void EventManager::handleEvent(Window& context) {
    sf::Event event;
    sf::Window* sfmlWindow = context.getContext();
    Character::MainCharacter& mainCharacter = Character::MainCharacter::getInstance();

    while (sfmlWindow->pollEvent(event)) {
        if (event.type == sf::Event::Closed) sfmlWindow->close();

        // keyboard
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) sfmlWindow->close();

            if (event.key.code == sf::Keyboard::D) {
                mainCharacter.moveTo(Interfaces::Direction::RIGHT);
            }

            if (event.key.code == sf::Keyboard::A) {
                mainCharacter.moveTo(Interfaces::Direction::LEFT);
            }

            if (event.key.code == sf::Keyboard::Space) {
                mainCharacter.jump();
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