#include "kernel/Collider.hpp"

using namespace Kernel;

Collider& Collider::getInstance() {
    static Collider collider;
    return collider;
}

void Collider::checkCollisions() {
    // graph traversal algorythm
}

void Collider::flush() {
    for (RegistredCollideObject collideObject : this->objects) {
        delete collideObject.view;
    }
    this->objects.clear();

    for (Collision* collision : this->collisions) {
        delete collision;
    }
    this->collisions.clear();    
}

void Collider::registerObject(Kernel::Interfaces::IDrawable* objectPtr, sf::Sprite* view) {
    RegistredCollideObject collideObject { objectPtr, view };
    this->objects.push_back(collideObject);
}

std::vector<Collision* > Collider::getCollisionsFor(Kernel::Interfaces::IDrawable* sourceObject) {
    std::vector<Collision* > objectCollisions;

    for (Collision* collision : this->collisions) {
        if (collision->objectSourcePtr == sourceObject) {
            objectCollisions.push_back(collision);
        }
    }

    return objectCollisions;
}

