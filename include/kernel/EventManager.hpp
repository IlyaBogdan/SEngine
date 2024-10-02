#pragma once

#include "kernel/Game.hpp"

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

