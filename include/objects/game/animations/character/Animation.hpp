#pragma once

#include "kernel/objects/game/animations/SpriteAnimation.hpp"
#include "kernel/objects/Animation.hpp"

namespace Animations__Character
{
    class Animation : public Animations::SpriteAnimation
    {
        public:
            Animation() {};
            sf::Sprite getSprite() override;
    };
}