#pragma once

#include "objects/game/animations/character/Animation.hpp"

namespace Animations__MainCharacter
{
    class Fall : public Animations__Character::Animation
    {
        public:
            Fall() {
                this->maxStep = 1;
                this->spriteRenderInterval = 100;
                this->spriteFolder = "character/MainCharacter/animations/fall";
            }
    };
}