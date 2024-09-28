#pragma once

#include "objects/game/animations/SpriteAnimation.hpp"
#include "objects/Animation.hpp"

namespace Animations__Character
{
    class Animation : public Animations::SpriteAnimation
    {
        public:
            Animation() {};
            //Animation(const Abstract::Animation& animationPtr) {};
            sf::Sprite getSprite() override;
    };
}