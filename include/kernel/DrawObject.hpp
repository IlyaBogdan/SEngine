#pragma once

#include "kernel/GameObject.hpp"

namespace Kernel
{

    class DrawObject : public Kernel::GameObject
    {
        public:
            DrawObject() {};
            virtual ~DrawObject() = 0 {};

            virtual void setXrotation(int x_rotation);
            virtual void draw() override;
            virtual void setCoordinate(Kernel::Interfaces::Coordinate coordinate);

        protected:
            std::string texturePath;
            sf::Texture texture;
            Kernel::Interfaces::Coordinate coordinate;
            int x_rotation = 0;

            virtual int loadTexture();
    };
}
