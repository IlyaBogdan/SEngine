#pragma once

#include "kernel/DrawObject.hpp"
#include "kernel/interfaces/IMoving.hpp"
#include "kernel/interfaces/IAnimated.hpp"
#include "kernel/interfaces/IAttacker.hpp"
#include "kernel/interfaces/IJumped.hpp"

namespace GameInstance::Objects
{
    class Character : public Kernel::DrawObject,
    Kernel::Interfaces::IAnimated, Kernel::Interfaces::IMoving, Kernel::Interfaces::IAttacker,
    Kernel::Interfaces::IJumped
    {
        public:
            Character() {};
            virtual ~Character() {};
            
            void setAnimation(Kernel::Animation* animation) override;
            virtual void handleCollisions(sf::Sprite* view) override;

        protected:
            bool moving;
            float movingSpeed;
            Kernel::Interfaces::MovingDirection movingDirection;
            Kernel::Interfaces::Coordinate coordinate;
            Kernel::Animation* animation;
    };
}
