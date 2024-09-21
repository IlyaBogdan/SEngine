#include "input/platforms/pc/windows/WindowsInputManager.hpp"

WindowsInputManager::WindowsInputManager() {

}

WindowsInputManager::~WindowsInputManager() {

}

MousePosition WindowsInputManager::getMousePosition() {
    int xPos = GET_X_LPARAM(lParam); 
    int yPos = GET_Y_LPARAM(lParam);

    MousePosition mousePosition{xPos, yPos};

    return mousePosition;
}
