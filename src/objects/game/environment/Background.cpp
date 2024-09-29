#include <iostream>
#include "objects/game/environment/Background.hpp"

using namespace GameEnvironment;

void Background::draw(Kernel::Window& context) {
    sf::Sprite sprite;
    sprite.setTexture(this->texture);

    sf::Vector2u windowSize = context.getContext()->getSize();
    sf::Vector2u textureSize = this->texture.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    sprite.setScale(scaleX, scaleY);
    context.getContext()->draw(sprite);
}

int Background::setTexture(std::string texturePath) {
    
    if (!this->texture.loadFromFile(texturePath)) {
        std::cerr << "Error: Could not load the texture!" << std::endl;
        return 0;
    }

    this->texture.setSmooth(true);
    this->texture.setRepeated(true);

    return 1;
}

void Background::setCoordinates(Kernel::Interfaces::Coordinates coordinates) {
    
}