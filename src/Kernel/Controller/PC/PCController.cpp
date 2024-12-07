#include <conio.h>
#include <typeinfo>

#include "Kernel/Controller/PC/PCController.hpp"
#include "Logging/Logger.hpp"

using namespace Kernel::Controller::PC;

void PCController::handleInput()
{
    if (int keyCode = _getch()) {
        std::string message = std::string(typeid(*this).name()) + ": Some button with code " + std::to_string(keyCode) + " was pressed";
        Logging::Logger::write(message);
    }
}