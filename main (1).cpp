#include <iostream>
#include "game.h"

int main() {
    displayIntro();
    int currentLocation = 1;
    int addCond = -1;
    bool gameRunning = true;
    char move[20] = {0};
    
    
    while (gameRunning) {
        displayCurrentLocation(currentLocation);
        std::cout << "- Открыть инвентарь" << std::endl;
        displayAdditionalLocation(currentLocation, addCond);
        std::cout << "Ваш ход: ";
        std::cin >> move;
        std::cout << std::endl;
        gameRunning = processMove(move, currentLocation, addCond);
    }
    return 0;
}
