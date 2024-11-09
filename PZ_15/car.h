#include <ostream>

class Car {public:
    Car() = default;
    Car(const char *brand, const char *color, const char *bodyType, double engineVolume, int probeg);
    Car(const char *brand, const char *color, const char *bodyType, double engineVolume);
    Car(const char *brand, const char *color, const char *bodyType);
    Car(const char *brand, const char *color);
    Car(const char *brand);
    
    ~Car();
    
    void setBrand(const char* brand);
    const char* getBrand();
    void setColor(const char* color);
    const char* getColor();    
    void setBodyType(const char *bodyType);
    const char* getBodyType();    
    void setEngineVolume(double engineVolume);
    double getEngineVolume();    
    void setProbeg(int probeg);
    int getProbeg();
    
    double fuelConsumption() const;
    void reduceProbeg(int amount);
    void printInfo() const;
    
    Car operator++();
    Car operator--();    
    
    bool operator< (Car other);
    bool operator> (Car other);
    
    friend std::ostream& operator<< (std::ostream& output, Car car);
   
private:
    const char *brand; 
    const char *color;
    const char *bodyType;  
    double engineVolume;
    int probeg;
};
