#include "kernel/Game.hpp"
#include "kernel/Menu.hpp"

using namespace Kernel;

Game::Game() {
    
}

Game::~Game() {

}

void Game::init() {
    this->window.setFullscreen(false);
    this->window.setSize(800, 800);
    this->window.setFPS(60);
}

void Game::update() {

}

void Game::render() {

}

void Game::loop() {
    Kernel::Menu menu = Menu();
    sf::RenderWindow* context = this->window.getContext();

    while (context->isOpen()) {

        this->eventManager.handleEvent(this->window);
        menu.draw(this->window);
        // draw loop
        context->clear();
		this->window.render();
	}
}