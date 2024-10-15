#include <iostream>
#include "game.h"

int main() {
    displayIntro();
    int currentLocation = 0;
    int addCond = -1;
    bool gameRunning = true;
    char move[20] = {0};
    
    
    while (gameRunning) {
        displayCurrentLocation(currentLocation);
        displayAdditionalLocation(currentLocation, addCond);
        //std::cout << "Ваш ход (инвентарь/уйти/ответить/осмотреться/перейти мост/осмотреть пьедестал/взять реликвию/осмотреть ширму/использовать зажигалку/наступить на плиты): ";
        std::cin >> move;
        gameRunning = processMove(move, currentLocation, addCond);
    }
    return 0;
}
