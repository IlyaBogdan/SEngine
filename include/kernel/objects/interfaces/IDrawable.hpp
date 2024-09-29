#pragma once

#include "kernel/graphics/Window.hpp"
#include <string>

namespace Kernel
{
    namespace Interfaces
    {
        struct Coordinates
        {
            float x, y;
        };
        
        class IDrawable
        {
            public:
                virtual void draw(Kernel::Window& context) = 0;
                virtual int setTexture(std::string texturePath) = 0;
                virtual void setCoordinates(Coordinates coordinates) = 0;
        }; 
    }
    
}