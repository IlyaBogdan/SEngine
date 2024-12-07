#include "Abstracts/Singleton.hpp"

using namespace Abstracts;

Singleton &Singleton::instance()
{
    static Singleton singleton;
    return singleton;
}
