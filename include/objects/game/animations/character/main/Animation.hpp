#pragma once

#include "objects/game/animations/SpriteAnimation.hpp"

namespace Animations__MainCharacter
{
    class Animation : public Animations::SpriteAnimation
    {
        public:
            sf::Sprite getSprite() override;
    };
}