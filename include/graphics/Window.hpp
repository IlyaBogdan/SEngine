#pragma once

namespace Graphics
{
    /**
     * Main context for graphics
     */
    class Window
    {
        public:
            static Window& Instance() {
                static Window window;
                return window;
            }

            void render();

        private:
            Window() {}
            ~Window() {}

            Window(Window const&);
            Window& operator= (Window const&);
    };
}