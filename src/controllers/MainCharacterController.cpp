#include "controllers/MainCharacterController.hpp"
#include "kernel/GameEngine.hpp"

using namespace GameInstance::Controllers;

MainCharacterController::MainCharacterController() {
    GameInstance::Objects::MainCharacter& mainCharacter = GameInstance::Objects::MainCharacter::getInstance();
    this->mainCharacter = &mainCharacter;
}

void MainCharacterController::intercept() {
    Kernel::GameEngine& game = Kernel::GameEngine::getInstance();

    Kernel::KeyboardHandlerMap menuKeyboardHandlers;
    Kernel::EventHandlerMap handlers_pressed {
        { sf::Keyboard::A, [this]() {
            this->mainCharacter->moveTo({ Kernel::Interfaces::XDirection::LEFT, Kernel::Interfaces::YDirection::STAND_Y });
        }},
        { sf::Keyboard::D, [this]() {
            this->mainCharacter->moveTo({ Kernel::Interfaces::XDirection::RIGHT, Kernel::Interfaces::YDirection::STAND_Y });
        }},
        { sf::Keyboard::K, [this]() {
            this->mainCharacter->attack();
        }},
        { sf::Keyboard::Space, [this]() {
            this->mainCharacter->jump();
        }},

        { sf::Keyboard::Escape, [this]() {
            Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
            game.window->close();
        }}
    };

    Kernel::EventHandlerMap handlers_released {
        { sf::Keyboard::A, [this]() {
            this->mainCharacter->stop();
        }},
        { sf::Keyboard::D, [this]() {
            this->mainCharacter->stop();
        }}
    };

    menuKeyboardHandlers.handlers_pressed = handlers_pressed;
    menuKeyboardHandlers.handlers_released = handlers_released;
    game.setKeyboardHandlers(menuKeyboardHandlers);
}
