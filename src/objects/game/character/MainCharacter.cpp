#include "objects/game/character/MainCharacter.hpp"

using namespace Character;

MainCharacter& MainCharacter::getInstance() {
    static MainCharacter mainCharacter;
    return mainCharacter;
}
