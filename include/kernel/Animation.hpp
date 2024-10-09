#pragma once

#include "kernel/DrawObject.hpp"

namespace Kernel
{
    class Animation : public DrawObject
    {
        public:
            Animation() {};
            virtual ~Animation() = 0 {};

            virtual void play();
            virtual void play(Kernel::Interfaces::Coordinate coordinate);
            virtual void draw() override;

        protected:
            sf::Clock timer;
            int spriteRenderInterval = 300;
            int animationStep = 0;
            int maxStep = 1;
            std::string sritesFolder;

            virtual int loadTexture() override;
            virtual void onDrawCallback();
    };
}
