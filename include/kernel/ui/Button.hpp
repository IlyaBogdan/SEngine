#pragma once

#include "kernel/UIElement.hpp"

namespace Kernel::UI
{
    struct ButtonConfig : UIElementConfig
    {

    };

    class Button : public UIElement
    {
        public:
            Button();
            Button(ButtonConfig config);
            virtual ~Button() {};

            void draw() override;
    };
}

