#include <iostream>
#include <math.h>

#include "kernel/physics/consts.h"
#include "objects/game/character/MainCharacter.hpp"
#include "objects/game/animations/character/main/StandBy.hpp"
#include "objects/game/animations/character/main/Moving.hpp"
#include "objects/game/animations/character/main/Jump.hpp"
#include "objects/game/animations/character/main/Fall.hpp"

using namespace Character;

sf::Clock jumpTimer;
float jumpDuration = 2.f;
float jumpSpeed = 60.f;
float maxHeight = 100.f;
Kernel::Interfaces::Coordinates startJump;

Animations__MainCharacter::StandBy standByAnimation = Animations__MainCharacter::StandBy();
Animations__MainCharacter::Moving movingAnimation = Animations__MainCharacter::Moving();
Animations__MainCharacter::Jump jumpAnimation = Animations__MainCharacter::Jump();
Animations__MainCharacter::Fall fallAnimation = Animations__MainCharacter::Fall();

MainCharacter::MainCharacter() {
    this->coordinates = Kernel::Interfaces::Coordinates{100.f, 800.f};
    this->setAnimation(&standByAnimation);
    this->movingSpeed = 0.05f;
    this->onTheGround = true;
}

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}

void MainCharacter::setCoordinates(Kernel::Interfaces::Coordinates coordinates) {
    if (coordinates.x < 100) {
        coordinates.x = 100;
    }

    if (coordinates.x > 1000) {
        coordinates.x = 1000;
    }

    if (coordinates.y > 800.f) {
        coordinates.y = 800.f;
    }

    this->coordinates = coordinates;
}

void MainCharacter::moveTo(enum Kernel::Interfaces::Direction direction) {
    Character::moveTo(direction);
    this->setAnimation(&movingAnimation);
}

void MainCharacter::stop() {
    Character::stop();
    this->setAnimation(&standByAnimation);
}

void MainCharacter::jump() {
    if (this->onTheGround) {
        jumpTimer.restart();
        this->onTheGround = false;
        startJump = this->coordinates;
    }

    float time = jumpTimer.getElapsedTime().asSeconds();
    float y = (jumpSpeed * time - (PHYSIC_G * pow(time, 2)) / 2) + startJump.y;

    if (time <= jumpDuration / 2) {
        this->coordinates.y = -y;
        this->setAnimation(&jumpAnimation);
    } else if (time > jumpDuration / 2 && time <= jumpDuration) {
        this->coordinates.y = y;
        this->setAnimation(&fallAnimation);
    } else {
        this->onTheGround = true;
        this->setAnimation(&standByAnimation);
    }
}
