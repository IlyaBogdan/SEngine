#include <iostream>

#include "Logging/Logger.hpp"

using namespace Logging;

void Logger::write(std::string logMessage)
{
    std::cout << logMessage << std::endl;
}