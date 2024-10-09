#include "objects/StaticObject.hpp"
#include "kernel/GameEngine.hpp"
#include "kernel/Collider.hpp"
#include <iostream>

using namespace GameInstance::Objects;

void StaticObject::handleCollisions(sf::Sprite* view) {
    Kernel::Collider& collider = Kernel::Collider::getInstance();
    collider.registerObject(this, view);
}