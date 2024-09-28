#pragma once

#include "objects/game/animations/character/Animation.hpp"

namespace Animations__MainCharacter
{
    class Jump : public Animations__Character::Animation
    {
        public:
            Jump() {
                this->maxStep = 5;
                this->spriteRenderInterval = 100;
                this->spriteFolder = "character/MainCharacter/animations/run";
            }
    };
}