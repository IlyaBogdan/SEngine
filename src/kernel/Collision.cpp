#include "kernel/Collision.hpp"

using namespace Kernel;

Collision::Collision(Kernel::DrawObject* objectSourcePtr, Kernel::DrawObject* objectDstPtr) {
    this->objectDstPtr = objectDstPtr;
    this->objectSourcePtr = objectSourcePtr;
}

void Collision::proccess() {
    this->objectDstPtr->onCollide();
    this->objectSourcePtr->onCollide();
}

