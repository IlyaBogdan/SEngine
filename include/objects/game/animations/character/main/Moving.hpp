#pragma once

#include "objects/game/animations/character/Animation.hpp"

namespace Animations__MainCharacter
{
    class Moving : public Animations__Character::Animation
    {
        public:
            Moving() {
                this->maxStep = 5;
                this->spriteRenderInterval = 100;
                this->spriteFolder = "character/MainCharacter/animations/run";
            }
    };
}