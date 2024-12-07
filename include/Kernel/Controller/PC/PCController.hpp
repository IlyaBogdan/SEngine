#pragma once

#include "Kernel/Controller/ControllerFabric.hpp"
#include "Kernel/Controller/AbstractController.hpp"

namespace Kernel::Controller::PC
{
    class PCController : public AbstractController
    {
        public:
            //ControllerState& getState() override;

        private:
            PCController() {};
            ~PCController() {};

            void handleInput() override;

            friend class ControllerFabric;
    };
}