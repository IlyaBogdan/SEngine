#pragma once

#include "objects/GameObject.hpp"

namespace GameObjectInterface
{
    class IInterractable
    {
        public:
            virtual void interract(Abstract::GameObject* oponent) = 0;
    };
}