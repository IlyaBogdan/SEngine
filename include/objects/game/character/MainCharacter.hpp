#pragma once

#include "objects/game/character/Character.hpp"
#include "kernel/objects/interfaces/IJumped.hpp"

namespace Character
{
    class MainCharacter : public Abstract::Character, Kernel::Interfaces::IJumped
    {
        public:
            static MainCharacter& getInstance();

            void setCoordinates(Kernel::Interfaces::Coordinates coordinates) override;
            void moveTo(enum Kernel::Interfaces::Direction direction) override;
            void stop() override;
            void jump() override;
            
        private:
            MainCharacter();
            ~MainCharacter() {}
            MainCharacter(MainCharacter const&);
            MainCharacter& operator= (MainCharacter const&);
            
            bool onTheGround;
    };
}