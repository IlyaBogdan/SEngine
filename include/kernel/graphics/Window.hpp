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
             * Set window size
             * @param width window width
             * @param height window height
             */
            Window* setSize(int width, int height);

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

            sf::RenderWindow* context;
            int width = 800;
            int height = 800;
            void applySettings();
            bool fullscreen = true;
            int fps = 60;
    };
}