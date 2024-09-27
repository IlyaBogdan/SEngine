#include "objects/interfaces/Drawable.hpp"

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
        Scene* addObject(GameObjectInterface::Drawable* object);

    private:
        std::vector<GameObjectInterface::Drawable*> objects;

};
