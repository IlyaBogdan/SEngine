#pragma once

#include <map>
#include <string>
#include "input/Controller.hpp"
#include "core/GameController.hpp"
#include <functional>

namespace Input
{
    class Keyboard : public Controller
    {            
        public:
            void handleInput(sf::Event *event, sf::Window* context);
            static std::map<sf::Keyboard::Key, std::function<void(Core::GameController*)>> controll;
    };
}