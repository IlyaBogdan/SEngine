#include "kernel/Collider.hpp"
#include <iostream>

using namespace Kernel;

Collider& Collider::getInstance() {
    static Collider collider;
    return collider;
}

void Collider::checkCollisions() {
    // graph traversal algorythm
    for (RegistredCollideObject sourceCollideObject : this->objects) {
        for (RegistredCollideObject dstCollideObject : this->objects) {
            if (sourceCollideObject != dstCollideObject) {
                if (sourceCollideObject.view->getGlobalBounds().intersects(dstCollideObject.view->getGlobalBounds())) {
                    // Обработка коллизии между sprites[i] и sprites[j]
                    std::cout << "Collision detected between sprite " << sourceCollideObject.source << " and sprite " << dstCollideObject.source << std::endl;
                    Collision* collision = new Collision(sourceCollideObject.source, dstCollideObject.source);

                    if (!this->collisionRegistred(collision)) {
                        this->collisions.push_back(collision);
                    }
                }
            }
        }
    }
}

bool Collider::collisionRegistred(Collision* collision) {
    for (Collision* registredCollision : this->collisions) {
        if (collision == registredCollision) {
            return true;
        }
    }

    return false;
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

