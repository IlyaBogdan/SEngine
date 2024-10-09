#pragma once

#include "kernel/GameObject.hpp"

namespace Kernel
{
    class Animation : public GameObject
    {
        public:
            Animation() {};
            virtual ~Animation() = 0 {};

            virtual void play();
            virtual void play(Kernel::Interfaces::Coordinate coordinate);
            virtual void draw() override;

            virtual void setXrotation(int x_rotation);
            void setCoordinate(Kernel::Interfaces::Coordinate coordinate);
        
        protected:
            sf::Texture texture;
            sf::Clock timer;
            int spriteRenderInterval = 300;
            int animationStep = 0;
            int maxStep = 1;
            int x_rotation = 0;
            std::string texturePath;
            Kernel::Interfaces::Coordinate coordinate;

            int Animation::setTexture(std::string texturePath);
            virtual void onDrawCallback();
    };
}
