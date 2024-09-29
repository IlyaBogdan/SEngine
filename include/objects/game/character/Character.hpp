#pragma once

#include "kernel/objects/GameObject.hpp"
#include "kernel/physics/PhysicObject.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"
#include "kernel/objects/interfaces/IMoving.hpp"
#include "kernel/objects/interfaces/IAnimated.hpp"

namespace Abstract
{
    class Character : public Physics::PhysicObject,
        public GameObject, public GameObjectInterface::IDrawable,
        public GameObjectInterface::IMoving, public GameObjectInterface::IAnimated
    {
        public:
            virtual ~Character() = default;

            void draw(Graphics::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setAnimation(Abstract::Animation* animation) override;
            virtual void setCoordinates(GameObjectInterface::Coordinates coordinates);

            void interruptAnimation() override;
            virtual void moveTo(enum GameObjectInterface::Direction direction);
            virtual void stop();

        protected:
            bool moving = false;
            float movingSpeed;
            sf::Texture texture;
            Abstract::Animation* animation;
            GameObjectInterface::Coordinates coordinates;
            GameObjectInterface::Direction direction;
    };    
}