#include "scene/Scene.hpp"

void Scene::render() {
    std::for_each(this->objects.begin(), this->objects.end(),
        [](GameObjectInterface::Drawable* objectPtr) {
            Graphics::Window& context = Graphics::Window::getInstance();
            objectPtr->draw(context);
        }
    );
}

Scene* Scene::addObject(GameObjectInterface::Drawable* object) {
    this->objects.push_back(object);
    return this;
}