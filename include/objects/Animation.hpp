#pragma once

#include "objects/GameObject.hpp"
#include "objects/interfaces/IDrawable.hpp"

namespace Abstract
{
    class Animation : public GameObject
    {
        public:
            virtual int setTexture(std::string texturePath) = 0;
            virtual void play(Graphics::Window& context) = 0;
            virtual void stop() = 0;

            virtual ~Animation() = default;

        protected:
            bool running;
    };
}