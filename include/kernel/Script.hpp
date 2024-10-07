#pragma once

#include "kernel/Level.hpp"

namespace Kernel
{
    class Script
    {
        public:
            Script();
            virtual ~Script() = 0;
            
            virtual void execute() = 0;
            virtual bool checkPoint() = 0;
    };
}
