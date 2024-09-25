#pragma once
#include <SFML/Graphics.hpp>

#include "input/controlls/Joystick.hpp"
#include "input/controlls/Keyboard.hpp"
#include "input/controlls/Mouse.hpp"

namespace Input
{
    class InputManager
    {
        public:
            InputManager();
            ~InputManager() {}

            bool handleEvent(sf::Event *event, sf::Window* context);
            
        private:
            InputManager(InputManager const&);
            InputManager& operator= (InputManager const&);

            Joystick* joystickController;
            Mouse* mouseController;
            Keyboard* keyboardController;
    };
}