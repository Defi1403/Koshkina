#include<iostream>
#include<cmath>
#include"topic.h"

void Human::setName(const char *name)
{
    firstName = name;
}

void Human::setSurname(const char *surname)
{
    secondName = surname;;
}

void Human::setAge(short age)
{
    if (age > 0) personAge = age;
    else std::cout << "Wrong age" << std::endl;
}

void Human::setWeight(double weight)
{
    if (weight > 0) personWeight = weight;
    else std::cout << "Wrong weight" << std::endl;
}

void Human::setHeight(short height)
{
    if (height > 0) personHeight = height;
    else std::cout << "Wrong height" << std::endl;
}

void Human::initHuman(const char *name, const char *surname, short age, double weight, short height)
{
    firstName = name;
    secondName = surname;
    personAge = age;
    personWeight = weight;
    personHeight = height;

}
        
void Human::indexWeight(double weight, short height) {
    double index = ((weight/2.205)/(height/39.37))*((weight/2.205)/(height/39.37));
    std::cout << "Индекс массы тела равен "<< index << std::endl;
}

void Human::yearOfBirth(short age) {
    int year = 2024 - age;
    std::cout << "Год рождения равен " << year << std::endl;
}

void Human::displayHuman() {
    std::cout << "Имя человека: " << firstName << std::endl;
    std::cout << "Фамилия человека: " << secondName << std::endl;
    std::cout << "Возраст человека: " << personAge << std::endl;
    std::cout << "Вес человека: " << personWeight << std::endl;
    std::cout << "Рост человека: " << personHeight;
}