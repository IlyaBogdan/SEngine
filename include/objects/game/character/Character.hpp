#pragma once

#include "objects/GameObject.hpp"
#include "physics/PhysicObject.hpp"
#include "objects/interfaces/Drawable.hpp"
#include "objects/interfaces/Moving.hpp"

namespace Abstract
{
    class Character : public Physics::PhysicObject, public GameObject, public GameObjectInterface::Drawable, public GameObjectInterface::Moving
    {
        public:
            virtual ~Character() = default;

            GameObjectInterface::Drawable* drawableCast() {
                return dynamic_cast<GameObjectInterface::Drawable*>(this);
            }
    };    
}