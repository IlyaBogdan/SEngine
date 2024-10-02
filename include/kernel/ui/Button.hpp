#pragma once

#include "kernel/UIElement.hpp"
#include "kernel/interfaces/IClickable.hpp"

namespace Kernel::UI
{
    struct ButtonConfig : UIElementConfig
    {
        UITextConfig text;
    };

    class Button : public UIElement, public Interfaces::IClickable
    {
        public:
            Button();
            explicit Button(ButtonConfig config);
            virtual ~Button() {};

            UITextConfig text;

            virtual void draw() override;
            void onClick() override {};

        protected:
            virtual void renderText();
    };
}

