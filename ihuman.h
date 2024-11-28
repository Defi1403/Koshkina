#pragma once
#include <iostream>
#include <string>
#include "age.h"

class IHuman {public:
    IHuman();
    IHuman(std::string firstName, std::string lastName, int age, double weight, double height);
    
    virtual ~IHuman();
    
    void setFirstName(std::string  firstName);
    std::string  getFirstName();
    void setLastName(std::string  lastName);
    std::string  getLastName();    
    void setAge(int age);
    int getAge();    
    void setWeight(double weight);
    double getWeight();    
    void setHeight(double height);
    double getHeight();
    
    virtual void readFromConsole() = 0;
	virtual void display();
	virtual void writeToFile();
    
private:
    std::string _firstName; 
    std::string _lastName;
    int _age;  
    double _weight;
    double _height;
};
