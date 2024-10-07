#pragma once

#include "kernel/Command.hpp"

namespace Commands
{
    class CloseGame : public Kernel::Command
    {
        public:
            void execute() override;
    };
}

