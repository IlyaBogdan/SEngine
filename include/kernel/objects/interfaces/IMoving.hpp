#pragma once

#include "kernel/graphics/Window.hpp"
#include <string>

namespace Kernel
{
    namespace Interfaces
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
}