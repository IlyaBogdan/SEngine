#pragma once

#include "kernel/UIElement.hpp"

namespace Kernel::UI
{
    struct MenuConfig
    {

    };

    class Menu : public UIElement
    {
        public:
            Menu();
            virtual ~Menu();

            void draw() override;

            std::vector<UIElement* > elements;
    };
}

