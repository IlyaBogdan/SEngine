#pragma once

#include <unordered_map>
#include <functional>
#include "SFML/Graphics.hpp"
#include "kernel/interfaces/IDrawable.hpp"
#include "kernel/Collision.hpp"

namespace Kernel
{
    typedef struct {
        Kernel::Interfaces::IDrawable* source;
        sf::Sprite* view;
    } RegistredCollideObject;

    inline bool operator ==(const RegistredCollideObject& rhs, const RegistredCollideObject& lhs) {
        return (rhs.source == lhs.source) && (rhs.view == lhs.view);
    }

    inline bool operator !=(const RegistredCollideObject& rhs, const RegistredCollideObject& lhs) {
        return (rhs.source != lhs.source) || (rhs.view != lhs.view);
    }

    /**
     * @brief Class for checking collision between objects
     */
    class Collider
    {
        public:
            static Collider& getInstance();

            void checkCollisions();
            void flush();
            void registerObject(Kernel::Interfaces::IDrawable* object, sf::Sprite* view);
            std::vector<Collision* > getCollisionsFor(Kernel::Interfaces::IDrawable* sourceObject);

        private:
            Collider() {};
            ~Collider() {};
            Collider(Collider const&);
            bool collisionRegistred(Collision* collision);

            std::vector<RegistredCollideObject > objects; 
            std::vector<Collision* > collisions;
    };
}

