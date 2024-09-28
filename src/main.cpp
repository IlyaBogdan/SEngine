#include <iostream>

#include "graphics/Window.hpp"
#include "event/EventManager.hpp"
#include "scene/Scene.hpp"
#include "objects/game/environment/Background.hpp"
#include "objects/game/character/MainCharacter.hpp"

int main() {
    // start setup
    Graphics::Window& window = Graphics::Window::getInstance();
    Event::EventManager& eventManager = Event::EventManager::getInstance();

    window.setFullscreen(true);
    window.setFPS(60);

    // Add background
    GameEnvironment::Background background = GameEnvironment::Background();
    background.setTexture("assets/background/background_0.png");
    
    // init main character
    Character::MainCharacter& mainCharacter = Character::MainCharacter::getInstance();
    
    // scene setup
    Scene scene = Scene();
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