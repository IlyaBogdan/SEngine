#pragma once

#include "kernel/Animation.hpp"
#include <functional>

namespace GameInstance::Animations
{
    class AttackAnimation : public Kernel::Animation
    {
        public:
            AttackAnimation() {};
            virtual ~AttackAnimation() = 0 {};

            void onFinish(std::function<void()> callback);

        protected:
            std::function<void()> finishCallback;
    };
}
