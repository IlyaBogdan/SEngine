#include "kernel/EventManager.hpp"

using namespace Kernel;

EventManager &EventManager::getInstance() {
    static EventManager eventManager;
    return eventManager;
}

void EventManager::handleEvent() {
    
}