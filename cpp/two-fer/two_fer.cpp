#include "two_fer.h"

namespace two_fer
{
    std::string two_fer(std::string name)
    {
        if (name == "")
        {
            name = "you";
        }
        return "One for " + name + ", one for me.";
    }
} // namespace two_fer
