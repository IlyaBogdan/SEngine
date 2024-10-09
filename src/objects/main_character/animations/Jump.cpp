#include "objects/main_character/animations/Fall.hpp"

using namespace GameInstance::Animations;

Fall::Fall() {
    this->colliding = true;
    this->sritesFolder = "recources/assets/character/MainCharacter/animations/fall";
    this->maxStep = 1;
    this->spriteRenderInterval = 200;
}