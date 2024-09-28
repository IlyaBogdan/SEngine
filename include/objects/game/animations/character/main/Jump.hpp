#pragma once

#include "objects/game/animations/character/Animation.hpp"

namespace Animations__MainCharacter
{
    class Jump : public Animations__Character::Animation
    {
        public:
            Jump() {
                this->maxStep = 3;
                this->spriteRenderInterval = 200;
                this->spriteFolder = "character/MainCharacter/animations/jump";
                this->loop = false;
            }
    };
}