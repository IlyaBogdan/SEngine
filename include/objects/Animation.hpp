#pragma once

namespace Abstract
{
    class Animation
    {
        public:
            virtual void play() = 0;

            virtual ~Animation() = default;
    };
}