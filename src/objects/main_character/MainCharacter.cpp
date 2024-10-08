#include "objects/main_character/MainCharacter.hpp"
#include "objects/main_character/animations/StandBy.hpp"
#include "objects/main_character/animations/Moving.hpp"
#include "kernel/interfaces/IDrawable.hpp"

GameInstance::Animations::StandBy standByAnimation;
GameInstance::Animations::Moving movingAnimation;

using namespace GameInstance::Objects;

MainCharacter::MainCharacter() {
    this->animation = &standByAnimation;
    this->coordinate = Kernel::Interfaces::Coordinate{0.f, 0.f};
    this->movingSpeed = 5.f;
}

MainCharacter::~MainCharacter() {

}

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}

void MainCharacter::draw() {
    this->animation->play(this->coordinate);
}

void MainCharacter::moveTo(Kernel::Interfaces::MovingDirection direction) {
    this->animation = &movingAnimation;
    int x_rotation = direction.x == Kernel::Interfaces::XDirection::LEFT ? 180 : 0;
    float x_difference = direction.x == Kernel::Interfaces::XDirection::LEFT ? -this->movingSpeed : this->movingSpeed;
    this->coordinate.x += x_difference;

    this->animation->setXrotation(x_rotation);
    standByAnimation.setXrotation(x_rotation);
}

void MainCharacter::stop() {
    this->animation = &standByAnimation;
}
