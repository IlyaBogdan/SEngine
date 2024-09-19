#include "input/controlls/InputState.hpp"
#include "input/InputAdapter.hpp"

/**
 * Manage all inputs from controllers
 */
class InputManager
{
    private:
        /**
         * Return info about controlls state
         */
        virtual InputState getState();
        
    public:
};
