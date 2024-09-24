#include <conio.h>
#include <windows.h>
#include <iostream>

#include "input/platforms/pc/windows/WindowsInputManager.hpp"
#include "input/controlls/platforms/pc/KeyboardEvent.hpp"
#include "input/controlls/platforms/pc/MouseEvent.hpp"

using namespace InputModule;

WindowsInputManager::WindowsInputManager() {
    
}

WindowsInputManager::~WindowsInputManager() {

}

void WindowsInputManager::handleKeyboard() {
    if (_kbhit()) {
        KeyboardEvent event;
        event.eventType = S_KEYBOARD_KEYDOWN;
        event.key = _getch();

        events.push(event);
    }
}



void WindowsInputManager::handleMouse() {
    
}
