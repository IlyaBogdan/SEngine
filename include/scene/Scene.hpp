#include "objects/interfaces/IDrawable.hpp"

class Scene
{
    public:
        Scene() {};
        ~Scene() {};

        /**
         * Render scene
         */
        void render();

        /**
         * Add new object to scene
         */
        Scene* addObject(GameObjectInterface::IDrawable* object);

    private:
        std::vector<GameObjectInterface::IDrawable*> objects;

};
