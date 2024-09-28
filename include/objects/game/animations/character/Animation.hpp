#pragma once

#include "objects/game/animations/SpriteAnimation.hpp"
#include "objects/Animation.hpp"

namespace Animations__Character
{
    class Animation : public Animations::SpriteAnimation
    {
        public:
            Animation() {};
            sf::Sprite getSprite() override;
    };
}