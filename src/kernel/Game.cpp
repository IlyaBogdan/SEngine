#include "kernel/Game.hpp"

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
    while (this->window.getContext()->isOpen()) {
        
        this->eventManager.handleEvent(this->window);

        // draw loop
        this->window.getContext()->clear();
		this->window.render();
	}
}