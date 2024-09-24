#pragma once
#include <queue>

#include "input/controlls/InputEvent.hpp"

namespace InputModule
{
    /**
     * Manage all inputs from controllers
     */
    class InputManager
    {           
        public:
            InputManager();
            ~InputManager();

            InputEvent* getEvent() {
                if (!this->events.empty()) {
                    InputEvent* eventPointer = &(this->events.back());
                    this->events.pop();
                    return eventPointer;
                }
                
                return NULL;
            }

            virtual void handleInput() {};
        
        protected:
            std::queue<InputEvent> events;
    };
}
