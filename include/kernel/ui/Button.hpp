#pragma once

#include "kernel/UIElement.hpp"

namespace Kernel::UI
{
    struct ButtonConfig : UIElementConfig
    {
        UITextConfig text;
    };

    class Button : public UIElement
    {
        public:
            Button();
            Button(ButtonConfig config);
            virtual ~Button() {};

            UITextConfig text;

            void draw() override;

        protected:
            virtual void renderText();
    };
}

