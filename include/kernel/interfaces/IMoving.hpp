#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    enum XDirection {
        STAND_X,
        LEFT,
        RIGHT,
    };

    enum YDirection {
        STAND_Y,
        UP,
        DOWN,
    };

    struct MovingDirection
    {
        XDirection x;
        YDirection y;
    };

    class IMoving
    {
        public:
            virtual void moveTo(MovingDirection direction) = 0;
            virtual void stop() = 0;
    };
}

