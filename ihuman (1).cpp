#include "Ihuman.h"

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

double IHuman::BodyIndex() {
    double massIndex = (_weight / 2.205) / ((_height / 39.37) * (_height / 39.37));
    return massIndex;
}

int IHuman::YearBirt() {
    return 2024 - _age;
}
    
void IHuman::display() {}

void IHuman::readFromConsole()
{
	setlocale(LC_ALL, "");
	std::string firstName; std::cout << "Введите имя: "; std::cin >> firstName; setFirstName(firstName);
	std::string lastName; std::cout << "Введите фамилию: "; std::cin >> lastName; setLastName(lastName);
	int age; std::cout << "Введите возраст: "; std::cin >> age; setAge(age);
	double weight; std::cout << "Введите вес: "; std::cin >> weight; setWeight(weight);
	double height; std::cout << "Введите рост: "; std::cin >> height; setHeight(height);
}
void IHuman::writeToFile() {}
