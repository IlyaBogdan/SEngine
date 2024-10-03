#pragma once

namespace Kernel
{
    /**
     * Abstract class for command
     */
    class Command
    {
        public:
            virtual ~Command() = 0 {};

            virtual void execute() = 0;
    };
}

