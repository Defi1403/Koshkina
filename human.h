class Human {public:
    Human() = default;    Human(const char *firstName, const char *lastName, int age, double weight, double height);
    Human(const char *firstName, const char *lastName, int age, double weight);    Human(const char *firstName, const char *lastName, int age);
    Human(const char *firstName, const char *lastName);    Human(const char *firstName);
    
    ~Human();
    
    void setFirstName(const char* firstName);
    const char* getFirstName();
    void setLastName(const char* lastName);
    const char* getLastName();    
    void setAge(int age);
    int getAge();    
    void setWeight(double weight);
    double getWeight();    
    void setHeight(double height);
    double getHeight();
    
    double calculateBMI() const;
    int calculateBirthYear() const;
    void printInfo() const;
    
    Human operator++();
    Human operator--();    
    
    bool operator< (Human other);
    bool operator> (Human other);
    
private:
    const char *firstName; 
    const char *lastName;
    int age;  
    double weight;
    double height;
};