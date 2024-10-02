#pragma once

#include "kernel/ui/UIElement.hpp"
#include "kernel/graphics/Window.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"

namespace Kernel
{
    namespace UI
    {
        class Button : public UIElement
        {
            public:
                Button() {};
                Button(std::string text);
                virtual ~Button() override {};

                virtual void draw(Kernel::Window& context) override;

            protected:
                std::string text;
        };
    }
}
