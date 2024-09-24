#pragma once

namespace Core
{
    /**
     * 
     */
    class GameLoop
    {
        private:

            bool running;
            
        public:

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
    };
}
