#pragma once

#include "kernel/GameEngine.hpp"

namespace Kernel
{
    class EventManager
    {
        public:
            static EventManager& getInstance();

            void handleEvent();

        private:
            EventManager() {};
            ~EventManager() {};
            EventManager(EventManager const&);  
    };
}

