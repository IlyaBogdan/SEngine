#pragma once

#include <SFML/Graphics.hpp>
#include "objects/Animation.hpp"

namespace Animations
{
    class SpriteAnimation : public Abstract::Animation
    {
        public:
            virtual sf::Sprite getSprite() = 0;

            int setTexture(std::string texturePath) override;
            void play(Graphics::Window& context) override;
            void stop() override;
            
            SpriteAnimation* setAnimationStep(int animationStep);
            SpriteAnimation* setMaxStep(int maxStep);
            SpriteAnimation* setSpriteInterval(int spriteRenderInterval);
            SpriteAnimation* setSpriteFolder(std::string spriteFolder);

        protected:
            int animationStep = 0;
            int maxStep = 1;
            int spriteRenderInterval = 400;
            std::string spriteFolder;
            sf::Clock timer;
            sf::Texture texture;

            std::string getSritePath();
    };
}