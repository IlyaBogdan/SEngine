#pragma once

#include "objects/game/animations/character/Animation.hpp"

namespace Animations__MainCharacter
{
    class StandBy : public Animations__Character::Animation
    {
        public:
            StandBy() {
                this->spriteRenderInterval = 300;
                this->spriteFolder = "character/MainCharacter/animations/stand_by";
            }
    };
}