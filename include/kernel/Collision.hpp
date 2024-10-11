#pragma once

#include "kernel/DrawObject.hpp"

namespace Kernel
{
    /**
     * @brief Abstract class for collision
     */
    class Collision
    {
        public:
            Collision() {};
            Collision(Kernel::DrawObject* objectSourcePtr, Kernel::DrawObject* objectDstPtr);
            ~Collision() {};

            virtual void proccess();

            Kernel::DrawObject* objectSourcePtr;
            Kernel::DrawObject* objectDstPtr;

            bool operator == (const Collision& other) const {
                return (other.objectDstPtr == this->objectDstPtr && other.objectSourcePtr == this->objectSourcePtr)
                    || (other.objectSourcePtr == this->objectDstPtr && other.objectDstPtr == this->objectSourcePtr);
            }
    };
}

