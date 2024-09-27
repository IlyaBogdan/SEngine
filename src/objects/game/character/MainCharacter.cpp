#include <iostream>
#include "objects/game/character/MainCharacter.hpp"

using namespace Character;

int animationStep = 0;
int maxStep = 1;
int spriteRenderInterval = 400;
sf::Clock timer;

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}

void MainCharacter::draw(Graphics::Window& context) {
    std::string spritePath = "assets/character/MainCharacter/animations/idle/step_" + std::to_string(animationStep) + ".png";
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
        context.getContext()->draw(sprite);
    }

    int elapsedTime = timer.getElapsedTime().asMilliseconds();
    if (elapsedTime >= spriteRenderInterval) {
        animationStep++;
        if (animationStep > maxStep) {
            animationStep = 0;
        }
        timer.restart();
        return;
    }
}

int MainCharacter::setTexture(std::string texturePath) {
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void MainCharacter::setCoordinates(GameObjectInterface::Coordinates coordinates) {

}