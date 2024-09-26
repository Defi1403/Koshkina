#include<iostream>
#include"main.h"

void readArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Введите " << i + 1 << " элемент:" << std::endl;
        std::cin >> arr[i];
    }
}
void readArray(double* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Введите " << i + 1 << " элемент:" << std::endl;
        std::cin >> arr[i];
    }
}
void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
void printArray(double* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
}
int sumArray(int* arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
double sumArray(double* arr, int size)
{
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}