#pragma once

#include "objects/game/character/Character.hpp"
#include "objects/interfaces/IJumped.hpp"

namespace Character
{
    class MainCharacter : public Abstract::Character, GameObjectInterface::IJumped
    {
        public:
            static MainCharacter& getInstance();

            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;
            void moveTo(enum GameObjectInterface::Direction direction) override;
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