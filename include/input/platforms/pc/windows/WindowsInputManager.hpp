#pragma once

#include <Windows.h>
#include "input/platforms/pc/PCInputManager.hpp"

namespace InputModule
{
    /**
     * Input manager for PC on Windows
     */
    class WindowsInputManager : public PCInputManager
    {
        private:
            
        public:
            WindowsInputManager();
            ~WindowsInputManager();

        protected:
            virtual void handleKeyboard();
            virtual void handleMouse();
    };
}
