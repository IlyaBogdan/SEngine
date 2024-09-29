#pragma once
#include "kernel/graphics/Window.hpp"

namespace Event
{
    class EventManager
    {
        public:
            static EventManager& getInstance();
            void handleEvent(Graphics::Window& context);

        private:
            EventManager() {};
            ~EventManager() {};
            EventManager(EventManager const&);
            EventManager& operator= (EventManager const&);            
    };
}