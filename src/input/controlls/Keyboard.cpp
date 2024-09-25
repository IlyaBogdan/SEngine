#include <SFML/Window/Keyboard.hpp>
#include "input/controlls/Keyboard.hpp"

using namespace Input;

void Keyboard::handleInput(sf::Event *event, sf::Window* context) {
    

    //std::function<void(Core::GameController*)> handler = this->controll[]
}

std::map<sf::Keyboard::Key, std::function<void(Core::GameController*)>> Keyboard::controll = {
    {sf::Keyboard::Escape, &Core::GameController::end}
};
