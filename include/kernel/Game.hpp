#pragma once

#include "SFML/Graphics.hpp"

namespace Kernel
{
    class Game
    {
        public:
            static Game& init();

            void update();
            void render();
            void poolEvents();
            void loop();

        private:
            Game();
            ~Game();
            Game(Game const&);

            const bool running();

            sf::RenderWindow* window;
            sf::Event event;
    };
}

