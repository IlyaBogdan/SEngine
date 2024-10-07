#pragma once

#include "kernel/GameObject.hpp"
#include "kernel/interfaces/IMoving.hpp"
#include "kernel/interfaces/IAnimated.hpp"

namespace GameInstance::Animations
{
    class StandBy : public Kernel::Animation
    {
        public:
            StandBy();
            ~StandBy() {};
    };
}
