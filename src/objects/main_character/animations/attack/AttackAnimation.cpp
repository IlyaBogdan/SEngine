#include "objects/main_character/animations/attack/AttackAnimation.hpp"

using namespace GameInstance::Animations;

void AttackAnimation::onFinish(std::function<void()> callback) {
    this->finishCallback = callback;
}
