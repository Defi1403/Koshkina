#include "child.h"

Child::Child()
{
    setFirstName("undefined");
    setLastName("undefined");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_grade = 0;
}

Child::Child(std::string firstName, std::string lastName, int age, double weight, double height, int grade) : 
    IHuman(firstName, lastName, age, weight, height), _grade(age::correctCount(grade)) {}

Child::~Child() {}

void Child::setGrade(int grade)
{ 
    this->_grade = age::correctCount(grade); 
} 
 
int Child::getGrade() 
{ 
    return _grade; 
}

void Child::display()
{
    setlocale(LC_ALL, "");
    IHuman::display();
    std::cout << "Класс: " << _grade << std::endl;
}
void CPP::readFromConsole()
{
    setlocale(LC_ALL, "");
	IHuman::readFromConsole();
	std::cout << "Введите класс: "; std::cin >> _grade;
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
			<< "Класс: " << _grade << std::endl
			<< "_____________________________________________" << std::endl;
	}
	out.close();
}

