#pragma once
#include "objects/GameObject.hpp"
#include "objects/interfaces/Drawable.hpp"

namespace GameEnvironment
{
    class Background : public Abstract::GameObject, public GameObjectInterface::Drawable
    {
        public:
            Background() {};
            ~Background() {};

            void draw(Graphics::Window& context) override;
            void setTexture(std::string texturePath) override;
            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;
    };
}