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
            void interruptAnimation() override;

            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;
            void moveTo() override;
            void stop() override;

            GameObjectInterface::IDrawable* drawableCast() {
                return dynamic_cast<GameObjectInterface::IDrawable*>(this);
            }

        protected:
            bool moving = true;
            sf::Texture texture;
            Abstract::Animation* animation;
    };    
}