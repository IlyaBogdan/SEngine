#include "kernel/Level.hpp"
#include <algorithm>

using namespace Kernel;

Level::Level() {

}

void Level::run() {
    while(this->running) {
        this->checkScripts();
    }
}

void Level::pause() {
    this->running = false;
}

void Level::checkScripts() {
    std::for_each(this->scripts.begin(), this->scripts.end(),
        [](Script* script) {
            if (script->checkPoint()) {
                script->execute();
                delete script;
            }
        }
    );
}

void Level::exit() {

}
