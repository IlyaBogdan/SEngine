#include "objects/main_character/animations/attack/AttackVariant_3.hpp"

using namespace GameInstance::Animations;

AttackVariant_3::AttackVariant_3() {
    this->colliding = true;
    this->sritesFolder = "recources/assets/character/MainCharacter/animations/attack/var_2";
    this->maxStep = 5;
    this->spriteRenderInterval = 100;
}
