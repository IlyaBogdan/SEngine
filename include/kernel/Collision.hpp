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
            ~Collision() {};

            virtual void proccess();

            Kernel::Interfaces::IDrawable* objectSourcePtr;
            Kernel::Interfaces::IDrawable* objectDstPtr;

            bool operator == (const Collision& other) const {
                return (other.objectDstPtr == this->objectDstPtr && other.objectSourcePtr == this->objectSourcePtr)
                    || (other.objectSourcePtr == this->objectDstPtr && other.objectDstPtr == this->objectSourcePtr);
            }
    };
}

