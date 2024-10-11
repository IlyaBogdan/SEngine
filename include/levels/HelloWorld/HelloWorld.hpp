#pragma once

#include "kernel/Level.hpp"
#include "kernel/Controller.hpp"

namespace GameInstance::Levels
{
    class HelloWorld : public Kernel::Level
    {
        public:
            HelloWorld();
            ~HelloWorld();

            void run() override;

        protected:
            Kernel::Controller* controller;

        private:        
    };
}

