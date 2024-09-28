#pragma once
#include "objects/GameObject.hpp"
#include "objects/interfaces/IDrawable.hpp"

namespace GameEnvironment
{
    class Background : public Abstract::GameObject, public GameObjectInterface::IDrawable
    {
        public:
            Background() {};
            ~Background() {};

            void draw(Graphics::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;

        private:
            sf::Texture texture;
    };
}