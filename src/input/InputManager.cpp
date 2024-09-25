#include "input/InputManager.hpp"

using namespace Input;

InputManager::InputManager() {
    this->joystickController = &(Joystick());
    this->keyboardController = &(Keyboard());
    this->mouseController = &(Mouse());
}

bool InputManager::handleEvent(sf::Event *event, sf::Window* context) {
    
    switch (event->type) {        
        case sf::Event::Closed:
            context->close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
            keyboardController->handleInput(event, context);
            break;

        default:
            break;
    }

    return true;
}
