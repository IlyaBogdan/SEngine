#include "kernel/scene/Scene.hpp"

void Scene::render() {
    std::for_each(this->objects.begin(), this->objects.end(),
        [](GameObjectInterface::IDrawable* objectPtr) {
            Graphics::Window& context = Graphics::Window::getInstance();
            objectPtr->draw(context);
        }
    );
}

Scene* Scene::addObject(GameObjectInterface::IDrawable* object) {
    this->objects.push_back(object);
    return this;
}