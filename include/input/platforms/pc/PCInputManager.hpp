#include "input/InputManager.hpp"
#include "input/controlls/platforms/pc/PCInputState.hpp"

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
        virtual MousePosition getMousePosition();
};

