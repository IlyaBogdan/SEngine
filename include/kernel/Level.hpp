#pragma once

#include <vector>
#include "kernel/DrawObject.hpp"
#include "kernel/Script.hpp"

namespace Kernel
{
    class Level
    {
        public:
            Level() {};
            virtual ~Level() = 0 {};
            
            virtual void run();
            void pause();
            void exit();

        protected:
            bool running = true;
            std::vector<DrawObject* > objects;
            std::vector<Script* > scripts;

            void checkScripts();
            void drawObjects();
    };
}
