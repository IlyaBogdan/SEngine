#pragma once
#include "input/controlls/InputEvent.hpp"

#define S_MOUSE_BUTTON_UP   0
#define S_MOUSE_BUTTON_DOWN 1
#define S_MOUSE_MOVE        2
#define S_MOUSE_SCROLL      3

namespace InputModule
{
    /**
     * Mouse coordinates
     */
    struct MousePosition {
        int x;
        int y;
    };

    /**
     * Info about mouse state
     */
    struct MouseEvent : InputEvent {
        int controller = S_MOUSE;
        MousePosition position;
        int button;
    };
}
