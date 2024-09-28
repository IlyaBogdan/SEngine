#pragma once

#include "graphics/Window.hpp"
#include <string>

namespace GameObjectInterface
{
    class IJumped
    {
        public:
            virtual void jump() = 0;
    };
}