#pragma once

#include "Kernel/Controller/ControllerState.hpp"

namespace Kernel::Controller
{
    class AbstractController
    {
        public:
            /**
             * Returns state of user's controller
             */
            //virtual ControllerState& getState() = 0;

            /**
             * Processing user input
             */
            virtual void handleInput() = 0;

            void update();
    };    
}