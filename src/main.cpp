#include <iostream>
#include "graphics/Window.hpp"
#include "event/EventManager.hpp"
#include "scene/Scene.hpp"
#include "objects/game/environment/Background.hpp"

int main() {
    // start setup
    Graphics::Window& window = Graphics::Window::getInstance();
    Event::EventManager& eventManager = Event::EventManager::getInstance();

    window.setFullscreen(true);
    window.setFPS(60);

    // scene setup
    Scene scene = Scene();
    GameEnvironment::Background background = GameEnvironment::Background();

    // main loop
    while (window.getContext()->isOpen())
	{
        eventManager.handleEvent(window);
        sf::Texture texture;
        //sf::IntRect(10, 10, 32, 32)
        if (!texture.loadFromFile("assets/background/background_0.png")) {
            std::cerr << "Error: Could not load the texture!" << std::endl;
            return -1;
        }

        texture.setSmooth(true);
        texture.setRepeated(true);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        // draw loop

        window.getContext()->clear();

        window.getContext()->draw(sprite);
        //texture.update(*window.getContext());
        
		window.render();
	}

    return 0;
}