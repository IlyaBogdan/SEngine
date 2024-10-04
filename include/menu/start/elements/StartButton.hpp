#pragma once

#include "kernel/UIElement.hpp"
#include "kernel/ui/Button.hpp"
#include "menu/shared/MenuButton.hpp"

namespace GameInstance::Menu::Elements
{
    class StartButton : public MenuButton
    {
        using MenuButton::MenuButton;

        public:
            //virtual void draw() override;
            virtual void onClick() override;

        protected:
            sf::Shape* shape;
    };
}
