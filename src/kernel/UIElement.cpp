#include "kernel/UIElement.hpp"
#include "kernel/GameEngine.hpp"

using namespace Kernel;

const bool UIElement::mouseOnElement() {
    Diapason area;
    area.xStart = this->x;
    area.xEnd = this->x + this->width;
    area.yStart = this->y;
    area.yEnd = this->y + this->height;

    GameEngine& game = GameEngine::getInstance();

    return game.mouseInArea(area);
}
