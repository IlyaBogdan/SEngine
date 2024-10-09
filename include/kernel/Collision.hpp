#pragma once

#include "kernel/interfaces/IDrawable.hpp"

namespace Kernel
{
    /**
     * @brief Abstract class for collision
     */
    class Collision
    {
        public:
            Collision() {};
            Collision(Kernel::Interfaces::IDrawable* objectSourcePtr, Kernel::Interfaces::IDrawable* objectDstPtr);
            virtual ~Collision() = 0 {};

            virtual void proccess() = 0;

            Kernel::Interfaces::IDrawable* objectSourcePtr;
            Kernel::Interfaces::IDrawable* objectDstPtr;
    };
}

