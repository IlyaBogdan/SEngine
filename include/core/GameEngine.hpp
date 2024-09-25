#pragma once

#include "core/GameLoop.hpp"
#include "input/InputManager.hpp"

namespace Core
{
    class GameEngine
    {            
        public:
            static GameEngine& getInstance() {
                static GameEngine engine;
                return engine;
            }

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
            GameEngine() {};
            ~GameEngine() {};
            GameEngine(GameEngine const&);
            GameEngine& operator= (GameEngine const&);

            Input::InputManager* inputManager;
    };
}
