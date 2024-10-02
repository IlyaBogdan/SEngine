#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    class IDrawable
    {
        public:
            virtual void draw() = 0;
    };
}

