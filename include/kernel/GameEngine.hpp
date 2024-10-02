#pragma once

#include <unordered_map>
#include <functional>
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

    using EventHandlerMap = std::unordered_map<int, std::function<void()>>;
    struct KeyboardHandlerMap {
        EventHandlerMap handlers_pressed;
        EventHandlerMap handlers_released;
    };

    struct MouseHandlerMap {
        EventHandlerMap handlers_pressed;
        EventHandlerMap handlers_released;
    };

    struct EventHandlers {
        MouseHandlerMap mouseEventHandlers;
        KeyboardHandlerMap keyboardEventHandlers;
    };

    class GameEngine
    {
        public:
            static GameEngine& getInstance();

            void update();
            void render();
            void poolEvents();
            void loop();
            void initKeyboardHandlers();

            bool mouseInArea(Diapason area);
            sf::RenderWindow* window;
        private:
            GameEngine();
            ~GameEngine();
            GameEngine(GameEngine const&);

            const bool running();
            sf::Event event;

            EventHandlers eventHandlers;
    };
}

