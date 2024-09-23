/**
 * 
 */
class GameEngine
{
    private:

        InputManager inputManager;
        GameLoop loop;
        
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
