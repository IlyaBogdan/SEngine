#pragma once

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
            GameLoop loop;
    };
}
