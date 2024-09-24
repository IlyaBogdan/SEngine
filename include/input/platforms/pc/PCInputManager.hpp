#pragma once
#include <iostream>
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
                std::cout << "PCInputManager handle input" << std::endl;
                this->handleMouse();
                this->handleKeyboard();
            }

        protected:
            virtual void handleKeyboard() {};
            virtual void handleMouse() {};
    };
}
