#pragma once

#include "graphics/Window.hpp"
#include <string>

namespace GameObjectInterface
{    
    enum Direction {
        LEFT,
        RIGHT
    };

    class IMoving
    {
        public:
            virtual void moveTo(enum Direction direction) = 0;
            virtual void stop() = 0;
    };
}