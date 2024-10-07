#include "objects/main_character/MainCharacter.hpp"
#include "objects/main_character/animations/StandBy.hpp"

GameInstance::Animations::StandBy standByAnimation;

using namespace GameInstance::Objects;

MainCharacter::MainCharacter() {
    this->animation = &standByAnimation;
}

MainCharacter::~MainCharacter() {

}

void MainCharacter::draw() {
    this->animation->play();
}

void MainCharacter::moveTo(Kernel::Interfaces::MovingDirection direction) {

}
