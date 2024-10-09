#pragma once

#include <functional>
#include "kernel/Animation.hpp"
#include "objects/main_character/animations/attack/AttackAnimation.hpp"

namespace GameInstance::Animations
{
    class Attack : public Kernel::Animation
    {
        public:
            Attack();
            ~Attack() {};

            void draw() override;
            void onFinish(std::function<void()> callback);
            void play(Kernel::Interfaces::Coordinate coordinate) override;

        protected:
            int currentVar = 0;
            int variantsCount = 3;

            AttackAnimation* currentAnimation;
            std::vector<AttackAnimation* > variants;
            std::function<void()> finishCallback;
    };
}
