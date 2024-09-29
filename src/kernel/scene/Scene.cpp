#include "kernel/scene/Scene.hpp"

using namespace Kernel;

void Scene::render() {
    std::for_each(this->objects.begin(), this->objects.end(),
        [](Interfaces::IDrawable* objectPtr) {
            Window& context = Window::getInstance();
            objectPtr->draw(context);
        }
    );
}

Scene* Scene::addObject(Interfaces::IDrawable* object) {
    this->objects.push_back(object);
    return this;
}