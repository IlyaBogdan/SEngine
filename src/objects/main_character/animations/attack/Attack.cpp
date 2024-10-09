#include "objects/main_character/animations/attack/Attack.hpp"
#include "objects/main_character/animations/attack/AttackVariant_1.hpp"
#include "objects/main_character/animations/attack/AttackVariant_2.hpp"
#include "objects/main_character/animations/attack/AttackVariant_3.hpp"

using namespace GameInstance::Animations;

AttackVariant_1 var1;
AttackVariant_2 var2;
AttackVariant_3 var3;

Attack::Attack() {
    this->variants.push_back(&var1);
    this->variants.push_back(&var2);
    this->variants.push_back(&var3);

    this->currentAnimation = this->variants[this->currentVar];
}

void Attack::onFinish(std::function<void()> callback) {
    this->currentAnimation->onFinish([this, callback]() {
        this->currentVar++;
        if (this->currentVar == this->variantsCount) {
            this->currentVar = 0;
        }
        this->currentAnimation = this->variants[this->currentVar];

        callback();
    });
}

void Attack::play(Kernel::Interfaces::Coordinate coordinate) {
    this->currentAnimation->setCoordinate(coordinate);
    this->currentAnimation->play();
}

void GameInstance::Animations::Attack::setXrotation(int x_rotation) {
    this->currentAnimation->setXrotation(x_rotation);
}

void Attack::draw() {
    
}
