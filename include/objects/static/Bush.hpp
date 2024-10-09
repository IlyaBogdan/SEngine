#pragma once

#include "objects/StaticObject.hpp"

namespace GameInstance::Objects
{
    enum BushVariant
    {
        BIG = 1,
        MEDIUM,
        SMALL,
        EXTRA_SMALL,
    };

    class Bush : public StaticObject
    {
        public:
            Bush(BushVariant variant);
            ~Bush() {};

        private:
            Bush() {};
    };
}
