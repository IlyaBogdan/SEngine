#include "objects/main_character/animations/StandBy.hpp"

using namespace GameInstance::Animations;

StandBy::StandBy() {
    this->sritesFolder = "recources/assets/character/MainCharacter/animations/stand_by";
    this->maxStep = 1;
    this->spriteRenderInterval = 300;
}