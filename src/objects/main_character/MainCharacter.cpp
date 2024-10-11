#include "objects/main_character/MainCharacter.hpp"
#include "objects/main_character/animations/StandBy.hpp"
#include "objects/main_character/animations/Moving.hpp"
#include "objects/main_character/animations/attack/Attack.hpp"
#include "objects/main_character/animations/Jump.hpp"
#include "objects/main_character/animations/Fall.hpp"

GameInstance::Animations::StandBy standByAnimation;
GameInstance::Animations::Moving movingAnimation;
GameInstance::Animations::Attack attackAnimation;
GameInstance::Animations::Jump jumpAnimation;
GameInstance::Animations::Fall fallAnimation;

using namespace GameInstance::Objects;

MainCharacter::MainCharacter() {
    this->colliding = true;
    this->animation = &standByAnimation;
    this->coordinate = Kernel::Interfaces::Coordinate{800.f, 50.f};
    this->movingSpeed = 1.5f;
    this->movingDirection.y = Kernel::Interfaces::YDirection::DOWN;
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

    if (!this->onGround) {
        this->animation = &fallAnimation;
        float y_difference ;

        if (this->movingDirection.y == Kernel::Interfaces::YDirection::DOWN) {
            y_difference = 0.5f;
        }

        this->coordinate.y += y_difference;
    }

    if (this->moving) {
        float x_difference = this->movingDirection.x == Kernel::Interfaces::XDirection::LEFT ? -this->movingSpeed : this->movingSpeed;
        if (!this->onGround) {
            x_difference *= 0.7f;
        } else {
            this->animation = &movingAnimation;
        }

        this->coordinate.x += x_difference;
    }

    this->animation->setOwner(this);
    this->animation->play(this->coordinate);
}

void MainCharacter::moveTo(Kernel::Interfaces::MovingDirection direction) {
    this->moving = true;
    this->movingDirection.x = direction.x;
}

void MainCharacter::stop() {
    this->moving = false;
    this->animation = &standByAnimation;
}

void MainCharacter::attack() {
    if (this->animation != &attackAnimation) {
        this->animation = &attackAnimation;
        attackAnimation.onFinish([this]() {
            this->stop();
        });        
    }
}

void MainCharacter::jump() {
    this->animation = &jumpAnimation;
}
