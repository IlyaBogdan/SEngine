#pragma once
#include "input/Controller.hpp"

namespace Input
{
    class Mouse : public Controller
    {            
        public:
            void handleInput(sf::Event *event, sf::Window* context) override;
    };
}
