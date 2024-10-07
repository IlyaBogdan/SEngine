#pragma once

#include "kernel/GameObject.hpp"

namespace Kernel
{
    class Animation : public GameObject
    {
        public:
            Animation() {};
            virtual ~Animation() = 0 {};

            void play();
            void draw() override;
        
        protected:
            sf::Texture texture;
            sf::Clock timer;
            int spriteRenderInterval = 300;
            int animationStep = 0;
            int maxStep = 1;
            std::string texturePath;

            int Animation::setTexture(std::string texturePath);
    };
}
