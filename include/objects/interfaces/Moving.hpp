#pragma once
#include "graphics/Window.hpp"
#include <string>

namespace GameObjectInterface
{    
    class Moving
    {
        public:
            virtual int setTexture(std::string texturePath) = 0;
    };
}