#pragma once

#include "objects/game/animations/character/main/Animation.hpp"

namespace Animations__MainCharacter
{
    class StandBy : public Animation
    {
        public:
            StandBy() {
                this->spriteRenderInterval = 300;
                this->spriteFolder = "character/MainCharacter/animations/stand_by";
            }
    };
}