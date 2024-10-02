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
            Menu() {};
            virtual ~Menu() = 0 {};

            void draw() override;

            std::vector<UIElement* > elements;
    };
}

