#include "levels/HelloWorld/HelloWorld.hpp"
#include "controllers/MainCharacterController.hpp"
#include "objects/main_character/MainCharacter.hpp"
#include "objects/static/Bush.hpp"

using namespace GameInstance::Levels;

GameInstance::Controllers::MainCharacterController mainCharacterController;

HelloWorld::HelloWorld() {
    this->controller = &mainCharacterController;

    Kernel::DrawObject* mainCharacter = &GameInstance::Objects::MainCharacter::getInstance();
    Kernel::DrawObject* bigBush = new GameInstance::Objects::Bush(GameInstance::Objects::BushVariant::BIG);
    Kernel::DrawObject* bigBush2 = new GameInstance::Objects::Bush(GameInstance::Objects::BushVariant::BIG);
    Kernel::DrawObject* smallBush = new GameInstance::Objects::Bush(GameInstance::Objects::BushVariant::SMALL);
    Kernel::DrawObject* mediumBush = new GameInstance::Objects::Bush(GameInstance::Objects::BushVariant::MEDIUM);

    bigBush->setCoordinate({ 450.f, 50.f });
    bigBush2->setCoordinate({ 0.f, 50.f });
    smallBush->setCoordinate({ 650.f, 50.f });
    mediumBush->setCoordinate({ 400.f, 50.f });

    this->objects.push_back(mainCharacter);
    this->objects.push_back(bigBush);
    this->objects.push_back(bigBush2);
    this->objects.push_back(smallBush);
    this->objects.push_back(mediumBush);
}

HelloWorld::~HelloWorld() {
    Kernel::DrawObject* mainCharacter = &GameInstance::Objects::MainCharacter::getInstance();
    for (Kernel::DrawObject* object : this->objects) {
        if (object != nullptr && object != mainCharacter) {
            delete object;
        }
    }
}

void HelloWorld::run() {
    Level::run();

    this->controller->intercept();
}
