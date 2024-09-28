#pragma once
#include "graphics/Window.hpp"
#include <string>

namespace GameObjectInterface
{
    struct Coordinates
    {
        
    };
    
    class IDrawable
    {
        public:
            virtual void draw(Graphics::Window& context) = 0;
            virtual int setTexture(std::string texturePath) = 0;
            virtual void setCoordinates(Coordinates coordinates) = 0;
    };
}