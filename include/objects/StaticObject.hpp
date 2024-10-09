#pragma once

#include "kernel/GameObject.hpp"

namespace GameInstance::Objects
{

    class StaticObject : public Kernel::GameObject
    {
        public:
            StaticObject() {};
            virtual ~StaticObject() = 0 {};

            virtual void setXrotation(int x_rotation);
            void draw() override;
            void setCoordinate(Kernel::Interfaces::Coordinate coordinate);

        protected:
            std::string texturePath;
            sf::Texture texture;
            Kernel::Interfaces::Coordinate coordinate;
            int x_rotation = 0;

            int setTexture(std::string texturePath);
    };
}
