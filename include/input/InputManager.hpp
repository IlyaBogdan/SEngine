#include "input/controlls/InputState.hpp"
#include "input/InputAdapter.hpp"

/**
 * Manage all inputs from controllers
 */
class InputManager
{
    private:
        InputAdapter adapter;

        /**
         * Return info about controlls state
         */
        InputState getState();
        
    public:

        InputManager();
        ~InputManager();

        /**
         * Check keyboard button state
         * @param 
         * @returns bool
         */
        bool getKeyState();

        /**
         * Return mouse position
         * @returns bool
         */
        int getMousePosition();

        /**
         * Check if button pressed
         * @param 
         * @returns bool
         */
        bool isButtonPressed();
};
