#include "adult.h"

Adult::Adult()
{
    setFirstName("undefined");
    setLastName("undefined");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_profession = "undefined";
}

Adult::Adult(std::string firstName, std::string lastName, int age, double weight, double height, std::string profession) : 
    IHuman(firstName, lastName, age, weight, height), _profession(age::correctAlpha(profession)) {}
    
Adult::~Adult() {}

void Adult::setProfession(std::string profession)
{ 
    this->_profession = age::correctAlpha(profession); 
} 
 
std::string Adult::getProfession()
{ 
    return _profession; 
}

void Adult::display()
{
    setlocale(LC_ALL, "");
    IHuman::display();
    std::cout << "Профессия: " << _profession << std::endl;
}

void CPP::readFromConsole()
{
    setlocale(LC_ALL, "");
	IHuman::readFromConsole();
	std::cout << "Введите профессию: "; std::cin >> _profession;
}
void CPP::writeToFile()
{
	std::ofstream out;
	out.open("Human.txt", std::ios::app);
	if (out.is_open())
	{
		out << "Имя: " << getFistName() << std::endl
			<< "Фамилия: " << getLastName << std::endl
			<< "Возраст: " << getAge() << std::endl
			<< "Вес: " << getWeight() << std::endl
			<< "Рост: " << getHeight() << std::endl
			<< "Профессия: " << _profession << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}
