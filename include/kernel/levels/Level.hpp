#pragma once

#include "kernel/scene/Scene.hpp"

namespace Abstract
{
    class Level
    {
        public:
            virtual ~Level() = default;

            void setup();
            void play();
            void stop();

        protected:
            Scene* scene;

            virtual void loadScene() = 0;
    };
}