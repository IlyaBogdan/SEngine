#pragma once

#include "levels/Level.hpp"

namespace Levels
{
    class Beginning : public Abstract::Level
    {
        public:
            void setup();
            void play();
            void stop();

        protected:
            void loadScene() override;
    };
}