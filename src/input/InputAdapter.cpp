#include "input/InputAdapter.hpp"
#include "input/platforms/pc/windows/WindowsInputManager.hpp"

using namespace InputModule;

InputManager* InputAdapter::getInputManager() {
    return new WindowsInputManager();
}
