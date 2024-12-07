#pragma once

#include <string>

namespace Logging
{
    class Logger
    {
        public:
            static void write(std::string logMessage);
    };
}
