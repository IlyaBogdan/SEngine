#pragma once

#include "kernel/objects/GameObject.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"

namespace Kernel
{
    namespace Abstract
    {
        class Animation : public GameObject
        {
            public:
                virtual int setTexture(std::string texturePath) = 0;
                virtual void play(Kernel::Window& context) = 0;
                virtual void stop() = 0;

                virtual ~Animation() = default;

            protected:
                bool running;
        };
    }
}
