#pragma once

class Human
{
    public:
        void setName(const char *name);
        void setSurname(const char *surname);
        void setAge(short age);
        void setWeight(double weight);
        void setHeight(short height);
        void initHuman(const char *name, const char *surname, short age, double weight, short height);
        void indexWeight(double weight, short height);
        void yearOfBirth(short age);
        void displayHuman();
    private:
        const char *firstName;
        const char *secondName;
        short personAge;
        double personWeight;
        short personHeight;
};