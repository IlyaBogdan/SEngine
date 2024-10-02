#pragma once

#include "kernel/graphics/Window.hpp"
#include "kernel/event/EventManager.hpp"
#include "kernel/objects/interfaces/IDrawable.hpp"
#include "kernel/ui/UIElement.hpp"

namespace Kernel
{
    class Menu : Interfaces::IDrawable
    {
        public:
            Menu();
            virtual ~Menu() {};

            void draw(Kernel::Window& context) override;
            int setTexture(std::string texturePath) override;
            void setCoordinates(Interfaces::Coordinates coordinates) override {};

            void open() {};
            void close() {};

        private:
            std::vector<UI::UIElement* > elements;
    };
}
