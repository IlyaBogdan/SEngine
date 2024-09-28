#pragma once

#include "objects/Animation.hpp"
#include <string>

namespace GameObjectInterface
{    
    class IAnimated
    {
        public:
            virtual void setAnimation(Abstract::Animation* animation) = 0;
            virtual void interruptAnimation() = 0;
    };
}