#pragma once

#define S_KEYBOARD 1
#define S_MOUSE 2
#define S_GAMEPAD 3

namespace InputModule
{
    /**
     * 
     */
    struct InputEvent {
        int controller;
        int eventType;
    };
}
