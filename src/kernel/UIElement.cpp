#include "kernel/UIElement.hpp"
#include "kernel/Game.hpp"

using namespace Kernel;

const bool UIElement::mouseOnElement() {
    Diapason area;
    area.xStart = this->x;
    area.xEnd = this->x + this->width;
    area.yStart = this->y;
    area.yEnd = this->y + this->height;

    Game& game = Game::getInstance();

    return game.mouseInArea(area);
}
