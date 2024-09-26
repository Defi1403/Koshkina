
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include"main.h"

using namespace std;

int main()
{
    int size = 5;
    int *arr = new int [size];
    double *darr = new double [size];
    readArray(arr, size);
    printArray(arr, size);
    std::cout << "Сумма элементов массива равна " << sumArray(arr, size) << std::endl;
    readArray(darr, size);
    printArray(darr, size);
    std::cout << "Сумма элементов массива равна " << sumArray(darr, size) << std::endl;
    return 0;
}
