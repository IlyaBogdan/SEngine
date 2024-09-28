#include "objects/game/animations/character/Animation.hpp"

using namespace Animations__Character;

sf::Sprite Animation::getSprite() {
    sf::Sprite sprite;
    
    sprite.setTexture(this->texture);
    sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    sprite.setPosition(this->coordinates); // absolute position
    sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

    // scale
    sprite.setScale(sf::Vector2f(1.5f, 1.5f)); // absolute scale factor
    sprite.scale(sf::Vector2f(1.5f, 1.5f)); // factor relative to the current scale
    sprite.setRotation(this->rotateAngle);
    
    return sprite;
}