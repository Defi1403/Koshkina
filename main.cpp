#include "human.h" 
#include <iostream> 
 
int main() { 
    Human* human1 = new Human("Kirill", "Grechanov", 13, 70.5, 175.3); 
    Human* human2 = new Human("Kir", "Grech", 13, 70.5, 171.3); 
     
 
    --*human1; 
    human1->printInfo();
 
    ++*human2; 
    human2->printInfo();
    
    
    if (*human1 > *human2) std::cout << "Рост "  << human1->getFirstName() << " больше" << std::endl; 
    else if (*human1 < *human2) std::cout << "Рост "  << human2->getFirstName() << " больше" << std::endl; 
    else std::cout << "Равны по росту"; 
    return 0; 
}