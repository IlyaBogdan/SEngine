#include "kernel/GameEngine.hpp"
#include "kernel/Animation.hpp"
#include "kernel/Collider.hpp"
#include <iostream>

using namespace Kernel;

int Animation::loadTexture() {
    this->texturePath = this->sritesFolder + "/step_" + std::to_string(animationStep) + ".png";

    return DrawObject::loadTexture();
}

void Animation::setOwner(DrawObject* owner) {
    this->owner = owner;
}

void Animation::play() {
    this->draw();
}

void Animation::play(Kernel::Interfaces::Coordinate coordinate) {
    this->coordinate = coordinate;
    this->draw();
}

void Animation::draw() {
    DrawObject::draw();

    this->onDrawCallback();
}

void Animation::handleCollisions(sf::Sprite *view) {
    Collider& collider = Collider::getInstance();
    collider.registerObject(this->owner, view);
}

void Animation::onDrawCallback() {
    int elapsedTime = this->timer.getElapsedTime().asMilliseconds();
    if (elapsedTime >= this->spriteRenderInterval) {
        this->animationStep++;
        if (this->animationStep > this->maxStep) {
            this->animationStep = 0;
        }
        this->timer.restart();
        return;
    }
}
