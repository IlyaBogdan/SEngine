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

            void setXrotation(int x_rotation);
        
        protected:
            sf::Texture texture;
            sf::Clock timer;
            int spriteRenderInterval = 300;
            int animationStep = 0;
            int maxStep = 1;
            int x_rotation = 0;
            std::string texturePath;

            int Animation::setTexture(std::string texturePath);
    };
}
