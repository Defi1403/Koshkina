#include<iostream>
#include<cmath>
#include"topic.h"
using namespace std;

int main()
{
    Human child;
    child.initHuman("Vanya", "Petrov", 10, 20, 120);
    child.setName("Ivan");
    child.displayHuman();
    std::cout << std::endl;
    Human *eldery = new Human;
    eldery->initHuman("Petr", "Nikitin", 80, 70, 180);
    eldery->setHeight(175);
    eldery->displayHuman();
    
    return 0;
}