#pragma once
#include <string>

namespace age
{
    enum humanAge
    {
        Kirill = 17,
        Kir = 18,
    };
    enum carProbeg
    {
        Lada = 50000,
        Volga = 70000,
    };
    enum animalAge
    {
        Boris = 3,
        Ginger = 5
    };
    std::string correctAlpha(std::string str);
    int correctCount (int count);
    double correctDecimal (double decimal);
}
