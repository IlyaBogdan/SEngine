#pragma once
#include "graphics/Window.hpp"

namespace GameObjectInterface
{
    class Drawable
    {
        virtual void draw(Graphics::Window* context) const = 0;

        virtual ~Drawable() = default;
    };
}