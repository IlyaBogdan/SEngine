#include <iostream>
#include "objects/game/character/MainCharacter.hpp"
#include "objects/game/animations/character/main/StandBy.hpp"
#include "objects/game/animations/character/main/Moving.hpp"

using namespace Character;

Animations__MainCharacter::StandBy standByAnimation = Animations__MainCharacter::StandBy();
Animations__MainCharacter::Moving movingAnimation = Animations__MainCharacter::Moving();

MainCharacter::MainCharacter() {
    this->coordinates = GameObjectInterface::Coordinates{100.f, 600.f};
    this->setAnimation(&standByAnimation);
    this->movingSpeed = 0.05f;
}

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}

void MainCharacter::setCoordinates(GameObjectInterface::Coordinates coordinates) {
    if (coordinates.x < 100) {
        coordinates.x = 100;
    }

    if (coordinates.x > 1000) {
        coordinates.x = 1000;
    }

    this->coordinates = coordinates;
}

void MainCharacter::moveTo() {
    this->setAnimation(&movingAnimation);
    this->moving = true;
}

void MainCharacter::stop() {
    this->setAnimation(&standByAnimation);
    this->moving = false;
}
