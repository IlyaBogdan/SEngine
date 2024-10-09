#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel::Interfaces
{
    class IAttacker
    {
        public:
            virtual void attack() = 0;
    };
}

