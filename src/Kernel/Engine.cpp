#include "SDL.h"

#include "Kernel/Engine.hpp"
#include "Kernel/Controller/AbstractController.hpp"
#include "Kernel/Controller/ControllerFabric.hpp"
#include "Graphics/Window.hpp"

using namespace Kernel;

Graphics::Window& window = Graphics::Window::instance();
Controller::AbstractController* controller = Controller::ControllerFabric::defineController();

Kernel::Engine::Engine() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Init(SDL_INIT_EVENTS);
    running = true;
}

Engine::~Engine() {
    delete controller;
}

int Engine::mainLoop() {
    while (running) {
        controller->handleInput();
        window.draw();
        return 0;
    }
}
