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
    this->movingSpeed = 1.5f;
}

MainCharacter::~MainCharacter() {

}

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}

void MainCharacter::draw() {
    int x_rotation = this->movingDirection.x == Kernel::Interfaces::XDirection::LEFT ? 180 : 0;
    this->animation->setXrotation(x_rotation);

    if (this->moving) {
        this->animation = &movingAnimation;
        float x_difference = this->movingDirection.x == Kernel::Interfaces::XDirection::LEFT ? -this->movingSpeed : this->movingSpeed;
        this->coordinate.x += x_difference;
    }

    this->animation->play(this->coordinate);
}

void MainCharacter::moveTo(Kernel::Interfaces::MovingDirection direction) {
    this->moving = true;
    this->movingDirection = direction;
}

void MainCharacter::stop() {
    this->moving = false;
    this->animation = &standByAnimation;
}
