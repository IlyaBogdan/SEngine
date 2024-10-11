#include "objects/character/Character.hpp"
#include "kernel/Collider.hpp"

using namespace GameInstance::Objects;

void Character::setAnimation(Kernel::Animation* animation) {
    this->animation = animation;
}

void Character::handleCollisions(sf::Sprite* view) {
    return;
}

void Character::onCollide() {
    if (this->moving) {
        float x_difference = this->movingDirection.x == Kernel::Interfaces::XDirection::LEFT ? this->movingSpeed : -this->movingSpeed;
        this->coordinate.x += x_difference;
    }
}