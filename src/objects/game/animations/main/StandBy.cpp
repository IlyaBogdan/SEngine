#include "objects/game/animations/character/main/StandBy.hpp"

using namespace Animations__MainCharacter;

sf::Sprite StandBy::getSprite() {
    sf::Sprite sprite;
    sprite.setTexture(this->texture);
    sprite.setOrigin(sf::Vector2f(25.f, 25.f));
    sprite.setPosition(sf::Vector2f(100.f, 500.f)); // absolute position
    sprite.move(sf::Vector2f(5.f, 10.f)); // offset relative to the current position

    // scale
    sprite.setScale(sf::Vector2f(1.5f, 1.5f)); // absolute scale factor
    sprite.scale(sf::Vector2f(1.5f, 1.5f)); // factor relative to the current scale
    
    return sprite;
}