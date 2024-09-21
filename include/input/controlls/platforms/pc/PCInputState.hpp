#include "input/controlls/InputState.hpp"
#include "input/controlls/platforms/pc/MouseState.hpp"
#include "input/controlls/platforms/pc/KeyboardState.hpp"

struct PCInputState : InputState {
    KeyboardState keyboard;
    MouseState mouse;
};
