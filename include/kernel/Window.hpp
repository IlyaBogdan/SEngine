#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel
{
    class Window
    {
        public:
            static Window& getInstance();

            void update();
            void render();

        private:
            Window();
            ~Window();
            Window(Window const&);

            sf::RenderWindow* window;
            sf::Event event;

            bool running = true;
    };
}

