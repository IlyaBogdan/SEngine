#pragma once

#include "input/InputManager.hpp"
#include "core/GameLoop.hpp"

namespace Core
{
    /**
     * 
     */
    class GameEngine
    {            
        public:
            ~GameEngine();

            bool running;

            /**
             * Entry point to game
             */
            bool init();

            /**
             * General iteration method
             */
            void run();

            /**
             * Stop engine work
             */
            void stop();

        private:

            InputModule::InputManager* inputManager;
            GameLoop loop;
    };
}
