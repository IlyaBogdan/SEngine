#include "objects/main_character/animations/Jump.hpp"

using namespace GameInstance::Animations;

Jump::Jump() {
    this->texturePath = "recources/assets/character/MainCharacter/animations/jump";
    this->maxStep = 3;
    this->spriteRenderInterval = 100;
}