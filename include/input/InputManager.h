#include "input/InputAdapter.h"

/**
 * Manage all inputs from controllers
 */
class InputManager
{
    private:
        InputAdapter adapter;
        
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
