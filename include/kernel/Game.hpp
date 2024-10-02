#pragma once

#include "SFML/Graphics.hpp"
#include "kernel/interfaces/IDrawable.hpp"

namespace Kernel
{
    struct Diapason
    {
        int xStart;
        int xEnd;
        int yStart;
        int yEnd;
    };

    class Game
    {
        public:
            static Game& getInstance();

            void update();
            void render();
            void poolEvents();
            void loop();

            bool mouseInArea(Diapason area);
            sf::RenderWindow* window;
        private:
            Game();
            ~Game();
            Game(Game const&);

            const bool running();
            sf::Event event;
    };
}

