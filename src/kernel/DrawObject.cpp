#include <iostream>
#include "kernel/DrawObject.hpp"
#include "kernel/GameEngine.hpp"
#include "kernel/consts.h"

using namespace Kernel;

DrawObject::DrawObject() {
    this->colliding = false;
}

sf::IntRect findOpaqueBounds(const sf::Image& image) {
    int left = image.getSize().x;
    int right = 0;
    int top = image.getSize().y;
    int bottom = 0;

    for (unsigned int y = 0; y < image.getSize().y; ++y) {
        for (unsigned int x = 0; x < image.getSize().x; ++x) {
            sf::Color pixel = image.getPixel(x, y);

            if (pixel.a != 0) {
                left = std::min(left, static_cast<int>(x));
                right = std::max(right, static_cast<int>(x));
                top = std::min(top, static_cast<int>(y));
                bottom = std::max(bottom, static_cast<int>(y));
            }
        }
    }

    if (left > right || top > bottom) {
        return sf::IntRect(0, 0, 0, 0);
    }

    return sf::IntRect(left, top, right - left + 1, bottom - top + 1);
}

int DrawObject::loadTexture() {
    sf::Image image;
    if (!image.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    sf::IntRect bounds = findOpaqueBounds(image);
    if (bounds.width <= 0 && bounds.height <= 0) {
        return 0;
    }

    this->texture.loadFromImage(image, bounds);
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
        //sprite->move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

        // scale
        float scale_x = this->x_rotation == 180 ? -1.f : 1.f;
        float scale_y = 1.f;

        sf::FloatRect spriteBounds = sprite->getLocalBounds();
        sprite->setOrigin(spriteBounds.width / 2.f, spriteBounds.height / 2.f);

        sprite->setScale(sf::Vector2f(scale_x, scale_y)); // absolute scale factor
        sprite->scale(sf::Vector2f(1.5f, 1.5f)); // absolute scale factor        

        if (this->colliding) {
            this->handleCollisions(sprite);
        }

        Kernel::GameEngine& game = Kernel::GameEngine::getInstance();
        game.window->draw(*sprite);

        if (DEBUG) {
            // borders for debug
            sf::RectangleShape border;
            border.setSize(sf::Vector2f(sprite->getGlobalBounds().width, sprite->getGlobalBounds().height));
            float border_x = this->coordinate.x;
            float bordrer_y = this->coordinate.y;
            border.setPosition({ border_x, bordrer_y });
            border.setFillColor(sf::Color::Transparent);
            border.setOutlineThickness(1.f);
            border.setOutlineColor(sf::Color::Red);
            game.window->draw(border);
        }
    }
}

void DrawObject::setXrotation(int x_rotation) {
    this->x_rotation = x_rotation;
}

void DrawObject::setCoordinate(Kernel::Interfaces::Coordinate coordinate) {
    this->coordinate = coordinate;
}