#pragma once

#include "kernel/graphics/Window.hpp"
#include <string>

namespace Kernel
{
    namespace Interfaces
    {
        class IJumped
        {
            public:
                virtual void jump() = 0;
        };
    }
}