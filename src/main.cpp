#include <iostream>

#include "kernel/graphics/Window.hpp"
#include "kernel/event/EventManager.hpp"
#include "kernel/scene/Scene.hpp"
#include "objects/game/environment/Background.hpp"
#include "objects/game/character/MainCharacter.hpp"

int main() {
    // start setup
    Kernel::Window& window = Kernel::Window::getInstance();
    Kernel::EventManager& eventManager = Kernel::EventManager::getInstance();

    window.setFullscreen(true);
    window.setFPS(60);

    // Add background
    GameEnvironment::Background background = GameEnvironment::Background();
    background.setTexture("assets/background/background_0.png");
    
    // init main character
    Character::MainCharacter& mainCharacter = Character::MainCharacter::getInstance();
    
    // scene setup
    Kernel::Scene scene = Kernel::Scene();
    scene.addObject(&background);
    scene.addObject(&mainCharacter);

    // main loop
    while (window.getContext()->isOpen())
	{
        eventManager.handleEvent(window);

        // draw loop
        window.getContext()->clear();
        scene.render();
		window.render();
	}

    return 0;
}