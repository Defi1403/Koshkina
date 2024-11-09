#include "car.h" 
#include <iostream> 
 
Car::Car(const char *brand, const char *color, const char *bodyType, double engineVolume, int probeg) { 
    this->brand = brand; 
    this->color = color; 
    this->bodyType = bodyType; 
    this->engineVolume = engineVolume; 
    this->probeg = probeg; 
    std::cout << "Создан объект " << brand << std::endl; 
} 
 
Car::Car(const char *brand, const char *color, const char *bodyType, double engineVolume) { 
    this->brand = brand; 
    this->color = color; 
    this->bodyType = bodyType; 
    this->engineVolume = engineVolume; 
    std::cout << "Создан объект " << brand << std::endl; 
} 
 
Car::Car(const char *brand, const char *color, const char *bodyType) { 
    this->brand = brand; 
    this->color = color; 
    this->bodyType = bodyType; 
    std::cout << "Создан объект  " << brand << std::endl; 
} 
 
Car::Car(const char *brand, const char *color) { 
    this->brand = brand; 
    this->color = color; 
    std::cout << "Создан объект " << brand << std::endl; 
} 
 
Car::Car(const char *brand) { 
    this->brand = brand; 
    std::cout << "Создан объект " << brand << std::endl; 
} 
 
Car::~Car() {} 
 
void Car::setBrand(const char* brand) 
{ 
    this->brand = brand; 
} 
 
const char* Car::getBrand() 
{ 
    return brand; 
} 
 
 
void Car::setColor(const char* color) 
{ 
    this->color = color; 
} 
 
const char* Car::getColor() 
{ 
    return color; 
} 
 
 
void Car::setBodyType(const char *bodyType) 
{ 
    if (bodyType > 0) this->bodyType = bodyType;
    else std::cout << "Некорректный ввод данных" << std::endl;
} 
 
const char* Car::getBodyType() 
{ 
    return bodyType; 
} 
 
 
void Car::setEngineVolume(double engineVolume) 
{ 
    if (engineVolume > 0) this->engineVolume = engineVolume; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
double Car::getEngineVolume() 
{ 
    return engineVolume; 
} 
 
 
void Car::setProbeg(int probeg) 
{ 
    if (probeg > 0) this->probeg = probeg; 
    else std::cout << "Некорректный ввод данных" << std::endl; 
} 
 
int Car::getProbeg() 
{ 
    return probeg; 
} 
 
 
double Car::fuelConsumption() const { 
    return engineVolume / probeg * 100; 
} 
 
void Car::reduceProbeg(int amount) {
    probeg -= amount;
} 
 
void Car::printInfo() const { 
    std::cout << "Бренд: " << brand << "\n"
        << "Цвет" << color << "\n" 
        << "Тип кузова: " << bodyType << "\n" 
        << "Объем двигателя: " << engineVolume << " л\n" 
        << "Пробег: " << probeg << " км\n";
} 
 
Car Car::operator++(){ 
    engineVolume += 0.5;
    return *this; 
} 
 
Car Car::operator--(){ 
    engineVolume -= 0.5; 
    return *this; 
} 
 
bool Car::operator < (Car other){ 
    return this->engineVolume < other.engineVolume; 
}

bool Car::operator > (Car other){ 
    return this->engineVolume > other.engineVolume; 
}

std::ostream& operator<<(std::ostream& output, Car car){
    output << "Бренд: " << car.brand << "\n"
        << "Цвет: " << car.color << "\n" 
        << "Тип кузова: " << car.bodyType << "\n" 
        << "Объем двигателя: " << car.engineVolume << " л\n" 
        << "Пробег: " << car.probeg << " км\n";
    return output;
}
