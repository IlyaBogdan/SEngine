#pragma once
#include "input/InputManager.hpp"

namespace InputModule
{
    /**
     * Multiplatform input adapter
     */
    class InputAdapter
    {        
        public:

            /**
             * Clossplatform method
             * Returns InputManager for platform
             * (now only for windows)
             */
            static InputManager* getInputManager();
    };
}
