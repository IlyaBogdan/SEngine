#pragma once

#include <SFML/Graphics.hpp>
#include "kernel/objects/Animation.hpp"

namespace Kernel
{
    namespace Animations
    {
        class SpriteAnimation : public Abstract::Animation
        {
            public:
                virtual sf::Sprite getSprite() = 0;

                int setTexture(std::string texturePath) override;
                void play(Kernel::Window& context) override;
                void stop() override;
                
                SpriteAnimation* setMaxStep(int maxStep);
                SpriteAnimation* setAnimationStep(int animationStep);
                SpriteAnimation* setSpriteInterval(int spriteRenderInterval);
                SpriteAnimation* setSpriteFolder(std::string spriteFolder);
                SpriteAnimation* setCoordinates(Interfaces::Coordinates coordinates);
                SpriteAnimation* setRotateAngle(int rotateAngle);

            private:
                

            protected:
                int animationStep = 0;
                int maxStep = 1;
                int spriteRenderInterval = 400;
                bool loop = true;
                std::string spriteFolder;
                sf::Clock timer;
                sf::Texture texture;
                sf::Vector2f coordinates;
                int rotateAngle = 0;

                std::string getSritePath();
        };
    }
}