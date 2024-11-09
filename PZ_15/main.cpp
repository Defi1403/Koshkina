#include "human.h"
#include "car.h"
#include "animal.h"
#include "age.h"
using namespace age;
#include <iostream> 
 
int main() { 
    Human* human1 = new Human("Kirill", "Grechanov", humanAge::Kirill, 70.5, 173.3);
    Human* human2 = new Human("Kir", "Grech", humanAge::Kir, 80.5, 181.3);
 
    --*human1; 
    std::cout << *human1;
 
    ++*human2; 
    std::cout << *human2;
    
    if (*human1 > *human2) std::cout << "Рост "  << human1->getFirstName() << " больше" << std::endl; 
    else if (*human1 < *human2) std::cout << "Рост "  << human2->getFirstName() << " больше" << std::endl; 
    else std::cout << "Равны по росту";
    
    std::cout << "_______________________________________" << std::endl;
    
    Car* car1 = new Car("Lada", "Grey", "Sedan", 2.1, carProbeg::Lada);
    Car* car2 = new Car("Volga", "White", "Hatchback", 1.2, carProbeg::Volga);
    
    --*car1; 
    std::cout << *car1;
 
    ++*car2; 
    std::cout << *car2;
    
    if (*car1 > *car2) std::cout << "Объем двигателя "  << car1->getBrand() << " больше" << std::endl; 
    else if (*car1 < *car2) std::cout << "Объем двигателя "  << car2->getBrand() << " больше" << std::endl; 
    else std::cout << "Равны по объему двигателя";
    
    std::cout << "_______________________________________" << std::endl;
    
    Animal* animal1 = new Animal("Boris", "Grey", "Cat", 5.1, animalAge::Boris);
    Animal* animal2 = new Animal("Ginger", "White", "Dog", 6.9, animalAge::Ginger);
    
    --*animal1; 
    std::cout << *animal1;
 
    ++*animal2; 
    std::cout << *animal2;
    
    if (*animal1 > *animal2) std::cout << "Вес "  << animal1->getName() << " больше" << std::endl; 
    else if (*animal1 < *animal2) std::cout << "Вес "  << animal2->getName() << " больше" << std::endl; 
    else std::cout << "Равны по весу";


    return 0; 
}