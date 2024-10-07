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

void Animation::draw() {
    std::string spritePath = this->texturePath + "/step_" + std::to_string(animationStep) + ".png";
    if (this->setTexture(spritePath)) {
        sf::Sprite sprite;
        sprite.setTexture(this->texture);
        sprite.setOrigin(sf::Vector2f(25.f, 25.f));
        sprite.setPosition(sf::Vector2f(100.f, 500.f)); // absolute position
        sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

        // scale
        sprite.setScale(sf::Vector2f(1.5f, 1.5f)); // absolute scale factor
        sprite.scale(sf::Vector2f(1.5f, 1.5f)); // factor relative to the current scale

        //sprite.setScale(scaleX, scaleY);

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