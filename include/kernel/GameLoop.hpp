#pragma once

namespace Kernel
{
    class GameLoop
    {
        public:
            static GameLoop& getInstance();
            void run();

        private:
            GameLoop();
            ~GameLoop();
            GameLoop(GameLoop const&);

            const bool running();
    };
}

