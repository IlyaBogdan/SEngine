#pragma once

#include <unordered_map>
#include <functional>
#include "SFML/Graphics.hpp"
#include "kernel/interfaces/IDrawable.hpp"

namespace Kernel
{
    /**
     * @brief Spatial range
     */
    struct Diapason
    {
        int xStart;
        int xEnd;
        int yStart;
        int yEnd;
    };

    /**
     * @brief Controllers event handler map
     */
    using EventHandlerMap = std::unordered_map<int, std::function<void()>>;

    /**
     * @brief Handlers for keyboard
     */
    struct KeyboardHandlerMap {
        EventHandlerMap handlers_pressed;
        EventHandlerMap handlers_released;
    };

    /**
     * @brief Handlers for mouse
     */
    struct MouseHandlerMap {
        EventHandlerMap handlers_pressed;
        EventHandlerMap handlers_released;
    };

    /**
     * @brief All handlers for all controllers
     */
    struct EventHandlers {
        bool handlerDefined(EventHandlerMap map, int key) {
            return map.find(key) != map.end();
        }

        MouseHandlerMap mouseEventHandlers;
        KeyboardHandlerMap keyboardEventHandlers;
    };

    /**
     * @brief Main class for game
     * 
     * 
     */
    class GameEngine
    {
        public:
            static GameEngine& getInstance();

            void update();
            void render();
            void poolEvents();
            void loop();

            bool mouseInArea(Diapason area);

            GameEngine* setMouseHandlers(MouseHandlerMap mouseHandlers);
            GameEngine* setKeyboardHandlers(KeyboardHandlerMap keyboardHandlers);

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

