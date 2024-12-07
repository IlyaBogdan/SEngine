#include "Kernel/Controller/ControllerFabric.hpp"
#include "Kernel/Controller/PC/PCController.hpp"

using namespace Kernel::Controller;

AbstractController *ControllerFabric::defineController()
{
    return new PC::PCController();
}