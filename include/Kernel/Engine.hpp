#pragma once

namespace Kernel
{
    /**
     * Singleton main class of game engine
     */
    class Engine
    {
    public:
        Engine() {}
        ~Engine();

        int mainLoop();

    private:
        Engine(const Engine&);
    };
}