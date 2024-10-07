#pragma once

#include "kernel/interfaces/IDrawable.hpp"

namespace Kernel
{
    class GameObject : public Interfaces::IDrawable
    {
        public:
            GameObject() {};
            virtual ~GameObject() = 0 {};
            
    };
}
