#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    struct MovingDirection
    {
        int x;
        int y;
    };

    class IMoving
    {
        public:
            virtual void moveTo(MovingDirection direction) = 0;
    };
}

