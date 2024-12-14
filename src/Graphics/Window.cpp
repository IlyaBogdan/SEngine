#include "SDL.h"
#include "Graphics/Window.hpp"
#include "Logging/Logger.hpp"

using namespace Graphics;

Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);
    _context = SDL_CreateWindow("Game Engine", 1200, 720, 0);
}

Window &Window::instance() {
    static Window window;
    return window;
}

void Window::draw() {
    bool running = true;
    while (running) {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    std::string message = std::string("Some button with was pressed");
                    Logging::Logger::write(message);
                    break;
            }
        }
    }
}

void Window::close() {
    SDL_DestroyWindow(_context);
    SDL_Quit();
}