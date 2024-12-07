#pragma once

namespace Abstracts
{
    class Command
    {
    private:
        /* data */
    public:
        Command(/* args */);
        virtual ~Command() = 0;

        /**
         * Execute 
         */
        void execute();
    };
}
