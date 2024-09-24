#pragma once
#include "input/InputManager.hpp"

namespace InputModule
{
    /**
     * Input manager for PC
     */
    class PCInputManager : public InputManager
    {
        private:
            
        public:
            PCInputManager();
            ~PCInputManager();

            virtual void handleInput() {
                this->handleMouse();
                this->handleKeyboard();
            }

        protected:
            virtual void handleKeyboard() {};
            virtual void handleMouse() {};
    };
}
