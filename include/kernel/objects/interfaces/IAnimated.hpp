#pragma once

#include "kernel/objects/Animation.hpp"
#include <string>

namespace Kernel
{
    namespace Interfaces
    {
        class IAnimated
        {
            public:
                virtual void setAnimation(Abstract::Animation* animation) = 0;
                virtual void interruptAnimation() = 0;
        };
    }
}