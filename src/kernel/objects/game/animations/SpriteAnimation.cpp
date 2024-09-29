#include <iostream>
#include "kernel/objects/game/animations/SpriteAnimation.hpp"

using namespace Kernel;
using namespace Animations;

void SpriteAnimation::play(Window& context) {
    std::string spritePath = this->getSritePath();

    if (this->setTexture(spritePath)) {
        sf::Sprite sprite = this->getSprite();
        context.getContext()->draw(sprite);
    }

    int elapsedTime = timer.getElapsedTime().asMilliseconds();
    if (elapsedTime >= this->spriteRenderInterval) {
        this->animationStep++;
        if (this->animationStep > maxStep) {
            if (this->loop) {
                this->animationStep = 0;
            } else {
                this->animationStep -= 1;
            }
        }
        this->timer.restart();
        return;
    }
}

int SpriteAnimation::setTexture(std::string texturePath) {
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void SpriteAnimation::stop() {
    this->running = false;
}

SpriteAnimation* SpriteAnimation::setAnimationStep(int animationStep) {
    this->animationStep = animationStep;
    return this;
}

SpriteAnimation* SpriteAnimation::setMaxStep(int maxStep) {
    this->maxStep = maxStep;
    return this;
}

SpriteAnimation* SpriteAnimation::setSpriteInterval(int spriteRenderInterval) {
    this->spriteRenderInterval = spriteRenderInterval;
    return this;
}

SpriteAnimation* SpriteAnimation::setSpriteFolder(std::string spriteFolder) {
    this->spriteFolder = spriteFolder;
    return this;
}

SpriteAnimation* SpriteAnimation::setCoordinates(Interfaces::Coordinates coordinates) {
    this->coordinates = sf::Vector2f(coordinates.x, coordinates.y);
    return this;
}

SpriteAnimation* SpriteAnimation::setRotateAngle(int rotateAngle) {
    this->rotateAngle = rotateAngle;
    return this;
}

std::string SpriteAnimation::getSritePath() {
    return "assets/" + this->spriteFolder + "/step_" + std::to_string(this->animationStep) + ".png";
}
