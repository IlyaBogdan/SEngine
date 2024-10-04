#pragma once

#include "kernel/interfaces/IClickable.hpp"
#include "kernel/interfaces/IDrawable.hpp"

namespace Kernel
{
    struct UIElementConfig
    {
        int x;
        int y;
        int width;
        int height;
    };

    struct UITextConfig
    {
        std::string text;
        int fontSize;
        sf::Color color;
        sf::Uint32 style;
    };
    

    class UIElement : public Interfaces::IDrawable, public Interfaces::IClickable
    {
        public:
            UIElement() {};
            virtual ~UIElement() = 0;
            virtual void onClick() override {};

            int x, y;
            int width, height;

            const bool mouseOnElement();            
    };
}

