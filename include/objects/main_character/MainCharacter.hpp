#pragma once

#include "kernel/interfaces/IControlling.hpp"
#include "objects/character/Character.hpp"
#include "kernel/Animation.hpp"

namespace GameInstance::Objects
{
    class MainCharacter : public Character, Kernel::Interfaces::IControlling
    {
        public:
            static MainCharacter& getInstance();
            
            void draw() override;
            void moveTo(Kernel::Interfaces::MovingDirection direction) override;
            void stop() override;
            void attack() override;
            void jump() override;

            Kernel::Animation* animation;

        private:
            MainCharacter();
            ~MainCharacter();
            MainCharacter(MainCharacter const&);
    };
}
