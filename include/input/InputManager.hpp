#include <queue>

#include "input/controlls/InputEvent.hpp"
#include "input/InputAdapter.hpp"

/**
 * Manage all inputs from controllers
 */
class InputManager
{
    private:
        std::queue<InputEvent> events;
        
    public:

        /**
         * Check if button pressed
         * @param 
         * @returns bool
         */
        virtual bool isButtonPressed();

        /**
         * Return info about controlls state
         */
        virtual InputState getInputState();
};
