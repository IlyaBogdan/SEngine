#pragma once

#include "Kernel/Controller/AbstractController.hpp"

namespace Kernel::Controller
{
    class ControllerFabric
    {
        public:
            /**
             * Defines the user's controller depending on the system
             * 
             * TODO: add support for other platforms later. Now it's working just for PC
             */
            static AbstractController* defineController();

        private:
            ControllerFabric() {};
            ~ControllerFabric() {};
    };
}