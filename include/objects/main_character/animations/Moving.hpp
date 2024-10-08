#pragma once

#include "kernel/Animation.hpp"

namespace GameInstance::Animations
{
    class Moving : public Kernel::Animation
    {
        public:
            Moving();
            ~Moving() {};
    };
}
