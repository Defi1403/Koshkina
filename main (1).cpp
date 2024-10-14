#include <iostream>
#include "game.h"

int main() {
    displayIntro();
    int currentLocation = 0;
    bool gameRunning = true;
    char move[20];
    
    while (gameRunning) {
        displayCurrentLocation(currentLocation);
        displayAdditionalLocation(currentLocation);
        //std::cout << "Ваш ход (инвентарь/уйти/ответить/осмотреться/перейти мост/осмотреть пьедестал/взять реликвию/осмотреть ширму/использовать зажигалку/наступить на плиты): ";
        std::cin >> move;
        gameRunning = processMove(move, currentLocation, hasDagger);
    }
    return 0;
}
