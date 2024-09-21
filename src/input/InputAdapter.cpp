#include "input/InputAdapter.hpp"
#include "input/platforms/pc/windows/WindowsInputManager.hpp"

InputManager InputAdapter::getInputManager() {
    return WindowsInputManager();
}
