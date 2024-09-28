#include <iostream>

#include "graphics/Window.hpp"
#include "event/EventManager.hpp"
#include "scene/Scene.hpp"
#include "objects/game/environment/Background.hpp"
#include "objects/game/character/MainCharacter.hpp"
#include "objects/game/animations/character/main/StandBy.hpp"
#include "objects/game/animations/character/main/Moving.hpp"
#include "objects/Animation.hpp"

sf::Clock timer;
bool animationFlag;

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
    Animations__MainCharacter::Moving movingAnimation = Animations__MainCharacter::Moving();
    
    // scene setup
    Scene scene = Scene();
    scene.addObject(&background);
    scene.addObject(&mainCharacter);

    // main loop
    while (window.getContext()->isOpen())
	{
        std::cout << timer.getElapsedTime().asSeconds() << std::endl;
        if (timer.getElapsedTime().asSeconds() > 3.f) {
            animationFlag = !animationFlag;
            timer.restart();
        }

        if (animationFlag) {
            mainCharacter.setAnimation(&standByAnimation);
        } else {
            mainCharacter.setAnimation(&movingAnimation);
        }

        eventManager.handleEvent(window);

        // draw loop
        window.getContext()->clear();
        scene.render();
		window.render();
	}

    return 0;
}