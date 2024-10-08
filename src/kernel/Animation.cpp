#include "kernel/GameEngine.hpp"
#include "kernel/Animation.hpp"
#include <iostream>

using namespace Kernel;

int Animation::setTexture(std::string texturePath) {
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void Animation::play() {
    this->draw();
}

void Animation::play(Kernel::Interfaces::Coordinate coordinate) {
    this->coordinate = coordinate;
    this->draw();
}

void Animation::draw() {
    std::string spritePath = this->texturePath + "/step_" + std::to_string(animationStep) + ".png";
    if (this->setTexture(spritePath)) {
        sf::Sprite sprite;
        sprite.setTexture(this->texture);
        sprite.setOrigin(sf::Vector2f(25.f, 25.f));
        sprite.setPosition(sf::Vector2f(this->coordinate.x, this->coordinate.y)); // absolute position
        sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

        // scale
        float scale_x = this->x_rotation == 180 ? -1.f : 1.f;
        float scale_y = 1.f;

        sprite.setScale(sf::Vector2f(scale_x, scale_y)); // absolute scale factor
        sprite.scale(sf::Vector2f(2.f, 2.f)); // absolute scale factor


        Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
        game.window->draw(sprite);
    }

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

void Animation::setXrotation(int x_rotation) {
    this->x_rotation = x_rotation;
}