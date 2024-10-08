#pragma once

namespace Kernel
{

    class Controller
    {
        public:
            virtual ~Controller() = 0 {};

            virtual void intercept() = 0;
    };
}

