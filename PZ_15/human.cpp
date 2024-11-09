#include "human.h" 
#include <iostream> 
 
Human::Human(const char *firstName, const char *lastName, int age, double weight, double height) { 
    this->firstName = firstName; 
    this->lastName = lastName; 
    this->age = age; 
    this->weight = weight; 
    this->height = height; 
    std::cout << "Создан объект " << firstName << std::endl; 
} 
 
Human::Human(const char *firstName, const char *lastName, int age, double weight) { 
    this->firstName = firstName; 
    this->lastName = lastName; 
    this->age = age; 
    this->weight = weight; 
    std::cout << "Создан объект " << firstName << std::endl; 
} 
 
Human::Human(const char *firstName, const char *lastName, int age) { 
    this->firstName = firstName; 
    this->lastName = lastName; 
    this->age = age; 
    std::cout << "Создан объект  " << firstName << std::endl; 
} 
 
Human::Human(const char *firstName, const char *lastName) { 
    this->firstName = firstName; 
    this->lastName = lastName; 
    std::cout << "Создан объект " << firstName << std::endl; 
} 
 
Human::Human(const char *firstName) { 
    this->firstName = firstName; 
    std::cout << "Создан объект " << firstName << std::endl; 
} 
 
Human::~Human() {} 

void Human::setFirstName(const char* firstName) 
{ 
    this->firstName = firstName; 
} 
 
const char* Human::getFirstName() 
{ 
    return firstName; 
} 
 
 
void Human::setLastName(const char* lastName) 
{ 
    this->lastName = lastName; 
} 
 
const char* Human::getLastName() 
{ 
    return lastName; 
} 
 
 
void Human::setAge(int age) 
{ 
    if (age > 0) this->age = age; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
int Human::getAge() 
{ 
    return age; 
} 
 
 
void Human::setWeight(double weight) 
{ 
    if (weight > 0) this->weight = weight; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
double Human::getWeight() 
{ 
    return weight; 
} 
 
 
void Human::setHeight(double height) 
{ 
    if (height > 0) this->height = height; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
double Human::getHeight() 
{ 
    return height; 
} 
 
 
double Human::calculateBMI() const { 
    return (weight / 2.205) / ((height / 39.37) * (height / 39.37)); 
} 
 
int Human::calculateBirthYear() const { 
    return 2024 - age; 
} 
 
void Human::printInfo() const { 
    std::cout << "Имя: " << firstName << " " << lastName << "\n" 
              << "Возраст: " << age << "\n" 
              << "Вес: " << weight << " kg\n" 
              << "Рост: " << height << " cm\n"; 
} 
 
Human Human::operator++(){ 
    height += 10;
    return *this; 
} 
 
Human Human::operator--(){ 
    height -= 10; 
    return *this; 
} 
 
bool Human::operator < (Human other){ 
    return this->height < other.height; 
}

bool Human::operator > (Human other){ 
    return this->height > other.height; 
}

std::ostream& operator<<(std::ostream& output, Human human){
    output << "Имя: " << human.firstName << " " << human.lastName << "\n" 
        << "Возраст: " << human.age << "лет\n" 
        << "Вес: " << human.weight << " кг\n" 
        << "Рост: " << human.height << " см\n";
    return output;
}