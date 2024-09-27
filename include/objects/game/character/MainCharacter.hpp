#pragma once

#include "objects/game/character/Character.hpp"

namespace Character
{
    class MainCharacter : public Abstract::Character
    {
        public:
            static MainCharacter& getInstance();

            void draw(Graphics::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;

            
        private:
            MainCharacter() {};
            ~MainCharacter() {}
            MainCharacter(MainCharacter const&);
            MainCharacter& operator= (MainCharacter const&);

            sf::Texture texture;
    };
}