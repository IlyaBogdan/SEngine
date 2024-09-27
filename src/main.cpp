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

    // scene setup
    Scene scene = Scene();
    GameEnvironment::Background background = GameEnvironment::Background();
    background.setTexture("assets/background/background_0.png");
    scene.addObject(&background);

    // init main character
    Character::MainCharacter& mainCharacter = Character::MainCharacter::getInstance();
    scene.addObject(mainCharacter.drawableCast());

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