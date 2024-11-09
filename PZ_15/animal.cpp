#include "animal.h" 
#include <iostream> 
 
Animal::Animal(const char *name, const char *species, const char *color, double weight, int age) { 
    this->name = name; 
    this->species = species; 
    this->color = color; 
    this->weight = weight; 
    this->age = age; 
    std::cout << "Создан объект " << name << std::endl; 
} 
 
Animal::Animal(const char *name, const char *species, const char *color, double weight) { 
    this->name = name; 
    this->species = species; 
    this->color = color; 
    this->weight = weight; 
    std::cout << "Создан объект " << name << std::endl; 
} 
 
Animal::Animal(const char *name, const char *species, const char *color) { 
    this->name = name; 
    this->species = species; 
    this->color = color; 
    std::cout << "Создан объект  " << name << std::endl; 
} 
 
Animal::Animal(const char *name, const char *species) { 
    this->name = name; 
    this->species = species; 
    std::cout << "Создан объект " << name << std::endl; 
} 
 
Animal::Animal(const char *name) { 
    this->name = name; 
    std::cout << "Создан объект " << name << std::endl; 
} 
 
Animal::~Animal(){} 
 
void Animal::setName(const char* name) 
{ 
    this->name = name; 
} 
 
const char* Animal::getName() 
{ 
    return name; 
} 
 
 
void Animal::setSpecies(const char* species) 
{ 
    this->species = species; 
} 
 
const char* Animal::getSpecies() 
{ 
    return species; 
} 
 
 
void Animal::setColor(const char *color) 
{ 
    this->color = color;

} 
 
const char* Animal::getColor() 
{ 
    return color; 
} 
 
 
void Animal::setWeight(double weight) 
{ 
    if (weight > 0) this->weight = weight; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
double Animal::getWeight() 
{ 
    return weight; 
} 
 
 
void Animal::setAge(int age) 
{ 
    if (age > 0) this->age = age; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
int Animal::getAge() 
{ 
    return age; 
} 
 
void Animal::reName(const char* newName) {
    name = newName;
}

void Animal::increaseWeight (int days) {
    weight += weight * 0,01 * days;
}
 
void Animal::printInfo() const { 
    std::cout << "Имя: " << name << "\n"
        << "Вид" << species << "\n" 
        << "Окрас: " << color << "\n" 
        << "Вес: " << weight << " кг\n" 
        << "Возраст: " << age << " лет\n";
} 
 
Animal Animal::operator++(){ 
    weight += 0.5;
    return *this; 
} 
 
Animal Animal::operator--(){ 
    weight -= 0.5; 
    return *this; 
} 
 
bool Animal::operator < (Animal other){ 
    return this->weight < other.weight; 
}

bool Animal::operator > (Animal other){ 
    return this->weight > other.weight; 
}

std::ostream& operator<<(std::ostream& output, Animal animal){
    output << "Имя: " << animal.name << "\n"
        << "Вид: " << animal.species << "\n" 
        << "Окрас: " << animal.color << "\n" 
        << "Вес: " << animal.weight << " л\n" 
        << "Возраст: " << animal.age << " км\n";
    return output;
}
