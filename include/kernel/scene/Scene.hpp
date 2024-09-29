#include "kernel/objects/interfaces/IDrawable.hpp"

namespace Kernel
{
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
            Scene* addObject(Interfaces::IDrawable* object);

        private:
            std::vector<Interfaces::IDrawable*> objects;

    };
}
