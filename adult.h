#pragma once
#include "Ihuman.h"

class Adult : virtual public IHuman
{public:
    Adult();
    Adult(std::string firstName, std::string lastName, int age, double weight, double height, std::string profession);
    
    ~Adult();
    
    void setProfession(std::string profession);
    std::string getProfession();
    
    void readFromConsole();
	void display();
	void writeToFile();
private:
    std::string _profession;
};
