#include "levels/HelloWorld/HelloWorld.hpp"
#include "controllers/MainCharacterController.hpp"
#include "objects/main_character/MainCharacter.hpp"

using namespace GameInstance::Levels;

GameInstance::Controllers::MainCharacterController mainCharacterController;

HelloWorld::HelloWorld() {
    this->controller = &mainCharacterController;
}

void HelloWorld::run() {
    Level::run();

    this->controller->intercept();
}
