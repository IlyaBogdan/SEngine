#include "Kernel/Engine.hpp"
#include "Kernel/Controller/AbstractController.hpp"
#include "Kernel/Controller/ControllerFabric.hpp"

using namespace Kernel;

Controller::AbstractController* controller = Controller::ControllerFabric::defineController();

Engine::~Engine()
{
    delete controller;
}

int Engine::mainLoop()
{
    controller->handleInput();    
    return 0;
}
