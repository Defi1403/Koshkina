#include <ostream>

class Animal {public:
    Animal() = default;
    Animal(const char *name, const char *species, const char *color, double weight, int age);
    Animal(const char *name, const char *species, const char *color, double weight);
    Animal(const char *name, const char *species, const char *color);
    Animal(const char *name, const char *species);
    Animal(const char *name);
    
    ~Animal();
    
    void setName(const char* name);
    const char* getName();
    void setSpecies(const char* species);
    const char* getSpecies();    
    void setColor(const char *color);
    const char* getColor();    
    void setWeight(double weight);
    double getWeight();    
    void setAge(int age);
    int getAge();
    
    void reName(const char* newName);
    void increaseWeight (int days);
    void printInfo() const;
    
    Animal operator++();
    Animal operator--();    
    
    bool operator< (Animal other);
    bool operator> (Animal other);
    
    friend std::ostream& operator<< (std::ostream& output, Animal animal);
   
private:
    const char *name; 
    const char *species;
    const char *color;  
    double weight;
    int age;
};
