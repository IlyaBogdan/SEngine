#pragma once

#include "kernel/Controller.hpp"
#include "objects/main_character/MainCharacter.hpp"

namespace GameInstance::Controllers
{
    class MainCharacterController : public Kernel::Controller
    {
        public:
            MainCharacterController();
            void intercept() override;

        protected:
            GameInstance::Objects::MainCharacter* mainCharacter;
    };
}

