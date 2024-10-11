#include "kernel/Collision.hpp"

using namespace Kernel;

Collision::Collision(Kernel::Interfaces::IDrawable* objectSourcePtr, Kernel::Interfaces::IDrawable* objectDstPtr) {
    this->objectDstPtr = objectDstPtr;
    this->objectSourcePtr = objectSourcePtr;
}

void Collision::proccess() {
    
}

