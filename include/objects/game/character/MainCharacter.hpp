#pragma once

#include "objects/game/character/Character.hpp"

namespace Character
{
    class MainCharacter : public Abstract::Character
    {
        public:
            static MainCharacter& getInstance();
            
        private:
            MainCharacter() {};
            ~MainCharacter() {}
            MainCharacter(MainCharacter const&);
            MainCharacter& operator= (MainCharacter const&);

    };
}