#include "objects/main_character/MainCharacter.hpp"
#include "kernel/GameEngine.hpp"
#include <iostream>

using namespace GameInstance::Objects;

sf::Texture texture;
sf::Clock timer;
int spriteRenderInterval = 300;
int animationStep = 0;
int maxStep = 1;

int setTexture(std::string texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    texture.setSmooth(true);
    texture.setRepeated(true);

    return 1;
}

MainCharacter::MainCharacter() {

}

MainCharacter::~MainCharacter() {

}

void MainCharacter::draw() {
    std::string spritePath = "recources/assets/character/MainCharacter/animations/stand_by/step_" + std::to_string(animationStep) + ".png";
    if (setTexture(spritePath)) {
        sf::Sprite sprite;
        sprite.setTexture(texture);
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

void MainCharacter::moveTo(Kernel::Interfaces::MovingDirection direction) {

}
