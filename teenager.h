#pragma once
#include "Ihuman.h"
#include "adult.h"
#include "child.h"

class Teenager : public Adult, Child
{public:
    Teenager();
    Teenager(std::string firstName, std::string lastName, int age, double weight, double height, std::string profession, int grade, std::string gender);
    
    ~Teenager();
    
    void setGender(std::string gender);
    std::string getGender();
    
    void readFromConsole();
	void display();
	void writeToFile();
private:
    std:: string _gender;
};
