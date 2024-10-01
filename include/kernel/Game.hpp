#pragma once

#include "kernel/graphics/Window.hpp"
#include "kernel/event/EventManager.hpp"

namespace Kernel
{
    class Game
    {
        public:
            Game();
            virtual ~Game();

            void init();
            void update();
            void render();

            void loop();

        private:
            Window& window = Window::getInstance();
            EventManager& eventManager = EventManager::getInstance();
    };
}
