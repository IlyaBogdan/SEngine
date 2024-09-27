#include "graphics/Window.hpp"
#include "event/EventManager.hpp"

int main() {
    // start setup
    Graphics::Window& window = Graphics::Window::getInstance();
    Event::EventManager& eventManager = Event::EventManager::getInstance();

    window.setFullscreen(true);
    window.setFPS(60);

    // main loop
    while (window.getContext()->isOpen())
	{
        eventManager.handleEvent(window);
		window.render();
	}

    return 0;
}