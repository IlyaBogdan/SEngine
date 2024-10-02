#pragma once

#include "kernel/graphics/Window.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"

namespace Kernel
{
    namespace UI
    {
        class UIElement : Interfaces::IDrawable
        {
            public:
                UIElement() {};
                virtual ~UIElement() = 0 {};

                virtual void draw(Kernel::Window& context) override;
                int setTexture(std::string texturePath) override;
                void setCoordinates(Interfaces::Coordinates coordinates) override;

                bool mouseOnElement(Kernel::Window& context);

            protected:
                int width = 160;
                int height = 80;
                sf::Texture texture;
        };
    }
}
