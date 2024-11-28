#include "Ihuman.h" 
#include <iostream> 

IHuman::IHuman() {
    this->_firstName = "undefined";
    this->_lastName = "undefined";
    this->_age = 0;
    this->_weight = 0.0;
    this->_height = 0.0;
}
IHuman::IHuman(std::string firstName, std::string lastName, int age, double weight, double height) : _firstName(age::correctAlpha(firstName)),
_lastName(age::correctAlpha(lastName)), _age(age::correctCount(age)), _weight(age::correctDecimal(weight)), _height(age::correctDecimal(height)) {}

IHuman::~IHuman() {} 

void IHuman::setFirstName(std::string firstName) 
{ 
    this->_firstName = age::correctAlpha(firstName); 
} 
 
std::string  IHuman::getFirstName() 
{ 
    return _firstName; 
} 
 
 
void IHuman::setLastName(std::string lastName) 
{ 
    this->_lastName = age::correctAlpha(lastName); 
} 
 
std::string  IHuman::getLastName() 
{ 
    return _lastName; 
} 
 
 
void IHuman::setAge(int age) 
{ 
    this->_age = age::correctCount(age); 
} 
 
int IHuman::getAge() 
{ 
    return _age; 
} 
 
 
void IHuman::setWeight(double weight) 
{ 
    this->_weight = age::correctDecimal(weight); 
} 
 
double IHuman::getWeight() 
{ 
    return _weight; 
} 
 
 
void IHuman::setHeight(double height) 
{ 
    this->_height = age::correctDecimal(height); 
} 
 
double IHuman::getHeight() 
{ 
    return _height; 
} 
 
void IHuman::display() { 
    std::cout << "Имя: " << _firstName << " " << _lastName << "\n" 
              << "Возраст: " << _age << "\n" 
              << "Вес: " << _weight << " kg\n" 
              << "Рост: " << _height << " cm\n"; 
}
void ITopic::readFromConsole()
{
	setlocale(LC_ALL, "");
	std::cout << "Введите имя: "; std::cin >> _firstName;
	std::cout << "Введите фамилию: "; std::cin >> _lastName;
	std::cout << "Введите возраст: "; std::cin >> _age;
	std::cout << "Введите вес: "; std::cin >> _weight;
	std::cout << "Введите рост: "; std::cin >> _height;
}
void ITopic::writeToFile() {}
