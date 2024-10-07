#pragma once

#include "SFML/Graphics.hpp"
#include "kernel/Animation.hpp"

namespace Kernel::Interfaces
{
    class IAnimated
    {
        public:
            virtual void setAnimation(Kernel::Animation* animation) = 0;
    };
}

