#pragma once

#include "kernel/objects/GameObject.hpp"

namespace GameObjectInterface
{
    class IInterractable
    {
        public:
            virtual void interract(Abstract::GameObject* oponent) = 0;
    };
}