#pragma once

#include "objects/game/character/Character.hpp"

namespace Character
{
    class MainCharacter : public Abstract::Character
    {
        public:
            static MainCharacter& getInstance();

            void setCoordinates(GameObjectInterface::Coordinates coordinates) override;
            void moveTo(enum GameObjectInterface::Direction direction) override;
            void stop() override;
            
        private:
            MainCharacter();

            ~MainCharacter() {}
            MainCharacter(MainCharacter const&);
            MainCharacter& operator= (MainCharacter const&);

    };
}