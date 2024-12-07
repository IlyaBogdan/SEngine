#pragma once

namespace Abstracts
{
    class Singleton
    {
    public:
        static Singleton& instance();

    private:
        Singleton() {}
        ~Singleton() {}
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
    };
}
