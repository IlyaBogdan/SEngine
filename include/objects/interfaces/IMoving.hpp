#pragma once
#include "graphics/Window.hpp"
#include <string>

namespace GameObjectInterface
{    
    class IMoving
    {
        public:
            virtual void moveTo() = 0;
            virtual void stop() = 0;
    };
}