#pragma once
#include "Ihuman.h"

class Child : virtual public IHuman
{public:
    Child();
    Child(std::string firstName, std::string lastName, int age, double weight, double height, int grade);
    
    ~Child();
    
    void setGrade(int grade);
    int getGrade();
    
    void readFromConsole();
	void display();
	void writeToFile();
private:
    int _grade;
};
