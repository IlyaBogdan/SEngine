#pragma once
#include "objects/GameObject.hpp"

namespace GameObjectInterface
{
    class Interractable
    {
        public:
            virtual void interract(Abstract::GameObject* oponent) const = 0;

            virtual ~Interractable() = default;
    };
}