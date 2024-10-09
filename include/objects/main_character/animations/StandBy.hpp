#pragma once

#include "kernel/Animation.hpp"

namespace GameInstance::Animations
{
    class StandBy : public Kernel::Animation
    {
        public:
            using Animation::Animation;

            StandBy();
            ~StandBy() {};
    };
}
