#pragma once

#include "kernel/objects/GameObject.hpp"
#include "kernel/physics/PhysicObject.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"
#include "kernel/objects/interfaces/IMoving.hpp"
#include "kernel/objects/interfaces/IAnimated.hpp"

namespace Abstract
{
    class Character : public Kernel::Physics::PhysicObject,
        public Kernel::Abstract::GameObject, public Kernel::Interfaces::IDrawable,
        public Kernel::Interfaces::IMoving, public Kernel::Interfaces::IAnimated
    {
        public:
            virtual ~Character() = default;

            void draw(Kernel::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setAnimation(Kernel::Abstract::Animation* animation) override;
            virtual void setCoordinates(Kernel::Interfaces::Coordinates coordinates);

            void interruptAnimation() override;
            virtual void moveTo(enum Kernel::Interfaces::Direction direction);
            virtual void stop();

        protected:
            bool moving = false;
            float movingSpeed;
            bool animationPlaying = false;
            sf::Texture texture;
            Kernel::Abstract::Animation* animation;
            Kernel::Interfaces::Coordinates coordinates;
            Kernel::Interfaces::Direction direction;
    };    
}