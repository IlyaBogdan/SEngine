#include "objects/main_character/animations/attack/AttackAnimation.hpp"

using namespace GameInstance::Animations;

void AttackAnimation::onFinish(std::function<void()> callback) {
    this->finishCallback = callback;
}

void GameInstance::Animations::AttackAnimation::draw() {
    if (this->animationStep >= this->maxStep) {
        this->animationStep = 0;
        this->finishCallback();
    }

    Animation::draw();
}
