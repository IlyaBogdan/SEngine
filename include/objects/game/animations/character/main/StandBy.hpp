#pragma once

#include "objects/game/animations/SpriteAnimation.hpp"

namespace Animations__MainCharacter
{
    class StandBy : public Animations::SpriteAnimation
    {
        public:
            sf::Sprite getSprite() override;
    };
}