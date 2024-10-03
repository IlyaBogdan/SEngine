#pragma once

#include "kernel/ui/Menu.hpp"

namespace GameInstance::Menu
{
    class StartMenu : public Kernel::UI::Menu
    {
        public:
            StartMenu();
            virtual ~StartMenu() {};

            void handleClick() override;
    };
}

