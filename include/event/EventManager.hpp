#pragma once
#include <SFML/Graphics.hpp>

namespace Event
{
    class EventManager
    {
        public:
            static EventManager& getInstance();
            void handleEvent(sf::Window* context);

        private:
            EventManager() {};
            ~EventManager() {};
            EventManager(EventManager const&);
            EventManager& operator= (EventManager const&);            
    };
}