/**
 * 
 */
class GameEngine
{
    private:

        InputManager inputManager;
        
    public:

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
};
