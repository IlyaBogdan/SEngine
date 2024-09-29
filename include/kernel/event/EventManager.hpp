#pragma once
#include "kernel/graphics/Window.hpp"

namespace Kernel
{
    class EventManager
    {
        public:
            static EventManager& getInstance();
            void handleEvent(Window& context);

        private:
            EventManager() {};
            ~EventManager() {};
            EventManager(EventManager const&);
            EventManager& operator= (EventManager const&);            
    };
}