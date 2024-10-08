#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    struct Coordinate
    {
        float x;
        float y;
    };

    class IDrawable
    {
        public:
            virtual void draw() = 0;
    };
}

