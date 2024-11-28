#include "teenager.h"

Teenager::Teenager() : Teenager("undefied", "undefied", 0, 0, 0, "undefied", 0, "undefied") {}

Teenager::Teenager(std::string firstName, std::string lastName, int age, double weight, double height, std::string profession, int grade, std::string gender) : 
    IHuman(firstName, lastName, age, weight, height), Adult(profession), Child(grade), _gender(gender) {}
    
Teenager::~Teenager() {}

void Teenager::setGender(std::string gender)
{ 
    this->_gender = age::correctAlpha(gender); 
} 
 
std::string Teenager::getGender()
{ 
    return _gender; 
}

void Teenager::display()
{
    setlocale(LC_ALL, "");
    IHuman::display();
    std::cout << "Профессия: " << getProfession() << std::endl;
    std::cout << "Класс обучения: " << getGrade() << std::endl;
    std::cout << "Пол: " << _gender << std::endl;
}

void Teenager::read()
{
    
}
