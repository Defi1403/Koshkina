#include "age.h"
#include <iostream>

std::string age::correctAlpha(std::string str)
{
    setlocale(LC_ALL, "");
    for (int i = 0; i < str.length(); ++i)
    {
        if (!isalpha(str[i]) && !ispunct(str[i]))
        {
            std::cout << "Некорректный ввод данных в поле\n_______________\n";
            return "undefined";
        }
    }
    return str;
}

int age::correctCount(int count)
{
    setlocale(LC_ALL, "");
    if (count >= 0) return count;
    else
    {
        std::cout << "Некорректный ввод данных в поле\n_______________\n";
        return 0;
    }
}

double age::correctDecimal (double decimal)
{
    setlocale(LC_ALL, "");
    if (decimal >= 0) return decimal;
    else
    {
        std::cout << "Некорректный ввод данных в поле\n_______________\n";
        return 0;
    }
}
