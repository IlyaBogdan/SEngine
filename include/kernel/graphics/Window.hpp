#pragma once
#include <SFML/Graphics.hpp>

namespace Kernel
{
    /**
     * Main context for graphics
     */
    class Window
    {
        public:
            static Window& getInstance();

            void render();

            /**
             * Set fullscren mode for context
             * @param fullscreen
             */
            Window* setFullscreen(bool fullscreen);

            /**
             * Set framerate for context
             * @param fps
             */
            Window* setFPS(int fps);

            /**
             * Return link to SFML context
             */
            sf::RenderWindow* getContext();

            bool getEvent(sf::Event *event);
            void Window::close();

        private:
            Window();
            ~Window() {}
            Window(Window const&);
            Window& operator= (Window const&);

            sf::RenderWindow* context;
            void applySettings();
            bool fullscreen = true;
            int fps = 60;
    };
}