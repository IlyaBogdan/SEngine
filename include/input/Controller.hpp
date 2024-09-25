#pragma once
#include <SFML/Graphics.hpp>

namespace Input
{
    class Controller
    {            
        public:
            virtual void handleInput(sf::Event *event, sf::Window* context) = 0;
    };
}