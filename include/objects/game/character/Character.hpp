#pragma once

#include "objects/GameObject.hpp"
#include "physics/PhysicObject.hpp"
#include "objects/interfaces/IDrawable.hpp"
#include "objects/interfaces/IMoving.hpp"
#include "objects/interfaces/IAnimated.hpp"

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
            virtual void moveTo();
            virtual void stop();

        protected:
            bool moving = false;
            float movingSpeed;
            sf::Texture texture;
            Abstract::Animation* animation;
            GameObjectInterface::Coordinates coordinates;
    };    
}