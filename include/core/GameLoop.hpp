#pragma once

namespace Core
{
    /**
     * 
     */
    class GameLoop
    {            
        public:
            GameLoop();
            
            /**
             * Entry point to game
             */
            GameLoop init();

            /**
             * General iteration method
             */
            void run();

            /**
             * Stop loop work
             */
            void stop();

        private:
            bool running;
    };
}
