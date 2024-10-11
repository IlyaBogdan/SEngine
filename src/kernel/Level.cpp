#include "kernel/Level.hpp"

using namespace Kernel;

void Level::run() {
    this->drawObjects();
    this->checkScripts();
}

void Level::pause() {
    this->running = false;
}

void Level::checkScripts() {
    for (Script* script : this->scripts) {
        if (script->checkPoint()) {
            script->execute();
            delete script;
        }
    }
}

void Level::drawObjects() {
    for (DrawObject* object : this->objects) {
        object->draw();
    }
}

void Level::exit() {

}
