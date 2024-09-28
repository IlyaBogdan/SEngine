#pragma once

#include "objects/game/animations/character/main/Animation.hpp"

namespace Animations__MainCharacter
{
    class Moving : public Animation
    {
        public:
            Moving() {
                this->maxStep = 5;
                this->spriteRenderInterval = 100;
                this->spriteFolder = "character/MainCharacter/animations/run";
            }
    };
}