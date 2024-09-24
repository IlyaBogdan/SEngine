#pragma once
#include "input/controlls/InputEvent.hpp"

#define S_KEYBOARD_KEYDOWN 1
#define S_KEYBOARD_KEYUP   0

namespace InputModule
{
    /**
     * Info about keyboard state
     */
    struct KeyboardEvent : InputEvent {
        int controller = S_KEYBOARD;
        int key;
    };
}
