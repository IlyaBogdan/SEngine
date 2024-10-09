#include "kernel/DrawObject.hpp"
#include "kernel/GameEngine.hpp"
#include <iostream>

using namespace Kernel;

DrawObject::DrawObject() {
    this->colliding = false;
}

int DrawObject::loadTexture() {
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void DrawObject::draw() {
    if (this->loadTexture()) {
        sf::Sprite* sprite = new sf::Sprite;
        sprite->setTexture(this->texture);
        sprite->setOrigin(sf::Vector2f(25.f, 25.f));
        sprite->setPosition(sf::Vector2f(this->coordinate.x, this->coordinate.y)); // absolute position
        sprite->move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

        // scale
        float scale_x = this->x_rotation == 180 ? -1.f : 1.f;
        float scale_y = 1.f;

        sprite->setScale(sf::Vector2f(scale_x, scale_y)); // absolute scale factor
        sprite->scale(sf::Vector2f(2.f, 2.f)); // absolute scale factor

        if (this->colliding) {
            this->handleCollisions(sprite);
        }

        Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
        game.window->draw(*sprite);
    }
}

void DrawObject::setXrotation(int x_rotation) {
    this->x_rotation = x_rotation;
}

void DrawObject::setCoordinate(Kernel::Interfaces::Coordinate coordinate) {
    this->coordinate = coordinate;
}