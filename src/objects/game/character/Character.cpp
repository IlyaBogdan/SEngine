#include <iostream>
#include "objects/game/character/Character.hpp"
#include "objects/game/animations/character/Animation.hpp"

using namespace Abstract;

void Character::draw(Graphics::Window& context) {
    if (this->moving) {
        float x = this->coordinates.x, y = this->coordinates.y;
        if (this->direction == GameObjectInterface::Direction::RIGHT) {
            x += this->movingSpeed;
        } else {
            x -= this->movingSpeed;
        }
        this->setCoordinates(GameObjectInterface::Coordinates{x, y});
    }
    
    int rotateAngle = this->direction ? 0 : 180;

    if (this->animation) {
        Animations__Character::Animation* animation = dynamic_cast<Animations__Character::Animation*>(this->animation);
        animation->setCoordinates(this->coordinates);
        animation->setRotateAngle(rotateAngle);
        animation->play(context);
    }
}

int Character::setTexture(std::string texturePath) {
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void Character::setAnimation(Abstract::Animation* animation) {
    this->animation = animation;
}

void Character::setCoordinates(GameObjectInterface::Coordinates coordinates) {
    this->coordinates = coordinates;
}

void Character::interruptAnimation() {
    this->animation->stop();
}

void Character::moveTo(enum GameObjectInterface::Direction direction) {
    this->direction = direction;
    this->moving = true;
}

void Character::stop() {
    this->moving = false;
}
