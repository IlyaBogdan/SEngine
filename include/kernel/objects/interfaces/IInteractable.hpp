#pragma once

#include "kernel/objects/GameObject.hpp"

namespace Kernel
{
    namespace Interfaces
    {
        class IInterractable
        {
            public:
                virtual void interract(Abstract::GameObject* oponent) = 0;
        };
    }
}