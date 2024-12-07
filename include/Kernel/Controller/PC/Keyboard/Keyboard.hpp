#pragma once

#include <conio.h>
#include <unordered_map>
#include <string>

namespace Kernel::Controller
{
    enum KeyCode
    {
        SPACE = 127
    };

    class Keyboard
    {
    public:
        Keyboard();
        virtual ~Keyboard() = 0;

        virtual std::unordered_map<KeyCode, std::string> GetPressedKey();
    };    
}