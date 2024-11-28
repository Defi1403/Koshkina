#include "Ihuman.h"
#include "adult.h"
#include "child.h"
using namespace age;
#include <iostream> 
 
int main() { 
    Adult* human1 = new Adult("Kirill", "Grechanov", 18, 70.5, 173.3, "teacher");
    Child human2("Kir", "Grech", 17, 80.5, 181.3, 4);
    
    IHuman** arr1 = new IHuman*[2] {human1, & human2};
    
    bool start1 = true;
    do
    {
        setlocale(LC_ALL, "");
        std::cout << "Выберете человека: 1 = Kirill, 2 = Kir, 3 = вывести все, 0 = выйти из программы" << std::endl;
        
        char choice1;
        std::cin >> choice1;
        switch (choice1)
        {
        case '1':
            arr1[0]->display();
            std::cout << "\n" << std::endl;
            break;
        case '2':
            arr1[1]->display();
            std::cout << "\n" << std::endl;
            break;
        case '3':
        for (int i = 0; i < 2; ++i)
        {
            arr1[i]->display();
            std::cout << "\n" << std::endl;
        }
            break;
        case '0':
            start1 = false;
            break;
        default:
            break;
        } 
    }
    while(start1);
    
    delete human1;
    delete arr1;
    
    return 0; 
}
