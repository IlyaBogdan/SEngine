#pragma once

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

    class UIElement : public Interfaces::IDrawable
    {
        public:
            UIElement() {};
            virtual ~UIElement() = 0 {};

            int x, y;
            int width, height;

            const bool mouseOnElement();
    };
}

