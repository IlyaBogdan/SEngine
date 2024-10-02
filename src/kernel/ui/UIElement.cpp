#include "kernel/ui/UIElement.hpp"

using namespace Kernel::UI;

void UIElement::draw(Kernel::Window& context) {
    
}

int UIElement::setTexture(std::string texturePath) {
    return 1;
}

void UIElement::setCoordinates(Interfaces::Coordinates coordinates) {

}

bool UIElement::mouseOnElement(Kernel::Window& context) {
    int mouseX = sf::Mouse::getPosition(*context.getContext()).x;
    int mouseY = sf::Mouse::getPosition(*context.getContext()).y;

    bool inWidth = mouseX >= this->width || mouseX <= this->width;
    bool inHeght = mouseY >= this->height || mouseY <= this->height;

    return inWidth || inHeght;
}
