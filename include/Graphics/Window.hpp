#pragma once

namespace Graphics
{
    /**
     * Main context for engine
     */
    class Window
    {
        public:
            static Window& instance();

            /**
             * Draw window on screen
             */
            void draw();

            void close();

        private:
            Window();
            ~Window() {}
            Window(const Window&);
            Window& operator=(const Window&);

            SDL_Window* _context;
    };
}