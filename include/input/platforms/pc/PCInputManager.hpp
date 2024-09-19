#include "input/InputManager.hpp"

/**
 * Input manager for PC
 */
class PCInputManager : InputManager
{
    private:
        /* data */
    public:
        PCInputManager();
        ~PCInputManager();

        /**
         * Check keyboard button state
         * @param 
         * @returns bool
         */
        virtual bool getKeyState();

        /**
         * Return mouse position
         * @returns bool
         */
        virtual int getMousePosition();

        /**
         * Check if button pressed
         * @param 
         * @returns bool
         */
        virtual bool isButtonPressed();
};

