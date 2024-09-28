#include "objects/game/animations/character/Animation.hpp"

using namespace Animations__Character;

sf::Sprite Animation::getSprite() {
    sf::Sprite sprite;
    
    sprite.setTexture(this->texture);
    sprite.setOrigin(sf::Vector2f(50.f, 50.f));
    sprite.setPosition(this->coordinates); // absolute position
    sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

    // scale
    if (this->rotateAngle) {
        sprite.setScale(2.f, -2.f);
    } else {
        sprite.setScale(2.f, 2.f);
    }
    

    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2, bounds.height / 2);
    sprite.setRotation(this->rotateAngle);
    
    return sprite;
}