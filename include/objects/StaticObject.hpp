#pragma once

#include "kernel/DrawObject.hpp"

namespace GameInstance::Objects
{

    class StaticObject : public Kernel::DrawObject
    {
        public:
            StaticObject() {};
            virtual ~StaticObject() = 0 {};

            virtual void handleCollisions(sf::Sprite* view) override;
    };
}
