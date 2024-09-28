#include <iostream>

#include "graphics/Window.hpp"
#include "event/EventManager.hpp"
#include "scene/Scene.hpp"
#include "objects/game/environment/Background.hpp"
#include "objects/game/character/MainCharacter.hpp"
#include "objects/game/animations/character/main/StandBy.hpp"
#include "objects/Animation.hpp"

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
    Animations__MainCharacter::StandBy standByAnimation = Animations__MainCharacter::StandBy();
    standByAnimation.setMaxStep(1)
        ->setSpriteFolder("character/MainCharacter/animations/stand_by")
        ->setSpriteInterval(400);
    mainCharacter.setAnimation(&standByAnimation);

    // scene setup
    Scene scene = Scene();
    scene.addObject(&background);
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