#include "objects/static/Bush.hpp"

using namespace GameInstance::Objects;

Bush::Bush(BushVariant variant) {
    this->texturePath = "recources/assets/static/bushes/bush_" + std::to_string(variant) + ".png";
    this->coordinate = Kernel::Interfaces::Coordinate{250.f, 100.f};
}
