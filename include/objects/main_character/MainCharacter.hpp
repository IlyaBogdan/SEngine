#pragma once

#include "kernel/interfaces/IControlling.hpp"
#include "objects/character/Character.hpp"
#include "kernel/Animation.hpp"

namespace GameInstance::Objects
{
    class MainCharacter : public Character, Kernel::Interfaces::IControlling
    {
        public:
            MainCharacter();
            ~MainCharacter();
            
            void draw() override;
            void moveTo(Kernel::Interfaces::MovingDirection direction) override;

            Kernel::Animation* animation;
    };
}
