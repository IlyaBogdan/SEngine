#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    class IClickable
    {
        public:
            virtual void onClick() = 0;
    };
}

