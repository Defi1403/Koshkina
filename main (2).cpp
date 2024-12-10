#include <iostream>
#include <fstream>
#include "teenager.h"

int main() {
    Adult* hum1 = new Adult;
    Child* hum2 = new Child;
    Adult* hum3 = new Adult;
    Child* hum4 = new Child;
    Teenager* hum5 = new Teenager;

    IHuman** arr = new IHuman*[5]{ hum1, hum2, hum3, hum4, hum5 };

    bool start = true;
    do {
        setlocale(LC_ALL, "");
        std::cout
            << "Выберите человека: " << std::endl
            << "1 = первый" << std::endl << "2 = второй" << std::endl
            << "3 = третий" << std::endl << "4 = четвертый" << std::endl
            << "5 = пятый" << std::endl << "0 = выход из программы" << std::endl;
        std::cout << "--------------------------------" << std::endl;

        char choice;
        std::cin >> choice;
        switch (choice) {
        case '1':
            arr[0]->readFromConsole();
            break;
        case '2':
            arr[1]->readFromConsole();
            break;
        case '3':
            arr[2]->readFromConsole();
            break;
        case '4':
            arr[3]->readFromConsole();
            break;
        case '5':
            arr[4]->readFromConsole();
            break;
        case '0': {
            char choice1;
            std::cout << "Вы хотите вывести информацию о каком-либо человеке: " << std::endl
                << "1 = да" << std::endl << "0 = нет" << std::endl;
            std::cin >> choice1;
            switch (choice1) {
            case '1': {
                char choice2;
                std::cout << "Для какого пользователя вы вхотите вывести информацию: " << std::endl
                    << "1 = первый" << std::endl << "2 = второй" << std::endl
                    << "3 = третий" << std::endl << "4 = четвертый" << std::endl
                    << "5 = пятый" << std::endl << "0 = выход из программы" << std::endl;
                std::cin >> choice2;
                switch (choice2) {
                case '1': arr[0]->display(); break;
                case '2': arr[1]->display(); break;
                case '3': arr[2]->display(); break;
                case '4': arr[3]->display(); break;
                case '5': arr[4]->display(); break;
                case '0': start = false; break;
                default: break;
                }
                break;
            }
            case '0':
                start = false;
                break;
            default:
                break;
            }
            break;
        }
        default:
            break;
        }
    } while (start);

    std::ofstream out("Ihuman.txt", std::ios::out | std::ios::trunc);
    out.close();

    for (int i = 0; i < 5; ++i) {
        arr[i]->writeToFile();
        std::cout << "Человек \"" << arr[i]->getFirstName() << " " << arr[i]->getLastName() << "\" успешно записан в файл." << std::endl;
    }

    delete hum1;
    delete hum2;
    delete hum3;
    delete hum4;
    delete hum5;
    delete[] arr;

    return 0;
}