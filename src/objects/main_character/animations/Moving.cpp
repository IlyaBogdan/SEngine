#include "objects/main_character/animations/Moving.hpp"

using namespace GameInstance::Animations;

Moving::Moving() {
    this->texturePath = "recources/assets/character/MainCharacter/animations/run";
    this->maxStep = 5;
    this->spriteRenderInterval = 100;
}