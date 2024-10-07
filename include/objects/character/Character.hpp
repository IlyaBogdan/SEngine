#pragma once

#include "kernel/GameObject.hpp"
#include "kernel/interfaces/IMoving.hpp"
#include "kernel/interfaces/IAnimated.hpp"

namespace GameInstance::Objects
{
    class Character : public Kernel::GameObject, Kernel::Interfaces::IAnimated, Kernel::Interfaces::IMoving
    {
        public:
            Character() {};
            virtual ~Character() {};
            
    };
}
