#include "objects/character/Character.hpp"

using namespace GameInstance::Objects;

void Character::setAnimation(Kernel::Animation *animation) {
    this->animation = animation;
}