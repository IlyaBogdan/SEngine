#pragma once

#include "kernel/objects/GameObject.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"

namespace GameEnvironment
{
    class Background : public Kernel::Abstract::GameObject, public Kernel::Interfaces::IDrawable
    {
        public:
            Background() {};
            ~Background() {};

            void draw(Kernel::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setCoordinates(Kernel::Interfaces::Coordinates coordinates) override;

        private:
            sf::Texture texture;
    };
}