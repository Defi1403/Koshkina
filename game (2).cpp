#include <iostream>
#include <cstring>
#include "game.h"

const char* inventory[MAX_INVENTORY_ITEMS] = {"веревка", "зажигалка", nullptr};
const char* locations[MAX_LOCATIONS] = {
    "Вы находитесь в лесу. Перед вами храм. Снаружи сидит Сфинкс.\nСфинкс задает вам вопрос: 'Кто ходит на четырех ногах утром, на двух днем и на трех вечером?'\n",
    "Вы видите мост над пропастью. Что будете делать?",
    "Вы в сокровищнице. Перед вами пьедестал с реликвией.",
    "Вы заметили скрытый проход в дальней части сокровищницы. Зайдя туда, вы видете нажимные плиты на полу"
};

const char* addLocations[MAX_LOCATIONS] = {
    "Вы находитесь в лесу. Перед вами храм. Снаружи сидит Сфинкс.\nСфинкс задает вам вопрос: 'Кто ходит на четырех ногах утром, на двух днем и на трех вечером?'\n",
    "Вы видите мост над пропастью. Что будете делать?",
    "Вы в сокровищнице. Перед вами пьедестал с реликвией.",
    "Вы заметили скрытый проход в дальней части сокровищницы. Зайдя туда, вы видете нажимные плиты на полу"
};

int lives = 3;

// Отображение вступительной информации
void displayIntro() {
    std::cout << "Добро пожаловать в игру 'Приключения в лесу'!\n";
    std::cout << "Вы начинающий искатель приключений. В вашем инвентаре веревка и зажигалка.\n";
}

// Отображение описания текущего местоположения
void displayCurrentLocation(int locationIndex) {
    std::cout << locations[locationIndex] << std::endl;
}

void displayAdditionalLocation(int locationIndex) {
    std::cout << addLocations[locationIndex] << std::endl;
}

// Обработка хода игрока
bool processMove(char* move, int& currentLocation) {
    if (strcmp(move, "инвентарь") == 0) {
        displayInventory();
    } else if (strcmp(move, "уйти") == 0) {
        std::cout << "Вы решили уйти. Конец игры.\n";
        return false;
    } else if (strcmp(move, "ответить") == 0) {
        char answer[20];
        std::cout << "Ваш ответ: ";
        std::cin >> answer;
        if (strcmp(answer, "человек") == 0) {
            std::cout << "Сфинкс открывает дверь в храм. Вы можете пройти внутрь.\n";
            currentLocation = 2;
            return true;
        } else {
            std::cout << "Неправильный ответ. Вы можете попробовать снова или уйти.\n";
            return true;
        }
    } else if (strcmp(move, "осмотреться") == 0 && currentLocation == 2) {
            std::cout << "Вы видите останки внизу пропасти. С помощью веревки вы спускаетесь вниз и находите кинжал.\n";
        inventory[2] = "кинжал";
        std::cout << "Вы забираетесь обратно на мост.\n";
        return true;
    } else if (strcmp(move, "перейти мост") == 0 && currentLocation == 2) {
        if (hasDagger) {
            std::cout << "Вы осматриваете механизм возле моста и обвязываете его веревкой. Мост не рухнет, и вы успешно переходите на другую сторону.\n";
            currentLocation = 3;
            return true;
        } else {
            std::cout << "Вы пытаетесь перейти мост, но он рушится, и вы падаете в пропасть. Вы теряете одну жизнь.\n";
            lives--;
            if (lives > 0) {
                std::cout << "С помощью веревки вы поднимаетесь наверх с другой стороны.\n";
                currentLocation = 3;
                return true;
            } else {
                std::cout << "Вы погибли. Конец игры.\n";
                return false;
            }
        }
    } else if (strcmp(move, "осмотреть пьедестал") == 0 && currentLocation == 3) {
        std::cout << "Вы видите надпись: 'Кто возьмет оружие, тот поплатится'.\n";
        return true;
    } else if (strcmp(move, "взять реликвию") == 0 && currentLocation == 3) {
        if () {
            std::cout << "Вы подменяете реликвию на кинжал. Ловушка не активируется.\n";
            return true;
        } else {
            std::cout << "Вы берете реликвию, и активируется ловушка. Вы теряете одну жизнь.\n";
            lives--;
            if (lives > 0) {
                return true;
            } else {
                std::cout << "Вы погибли. Конец игры.\n";
                return false;
            }
        }
    } else if (strcmp(move, "осмотреть ширму") == 0 && currentLocation == 3) {
        std::cout << "Вы видите проход за ширмой, ведущий в другую комнату.\n";
        currentLocation = 4;
        return true;
    } else if (strcmp(move, "использовать зажигалку") == 0 && currentLocation == 4) {
        std::cout << "Вы используете зажигалку и читаете надписи на стенах. Вы выясняете последовательность нажатия на плиты.\n";
        std::cout << "Вы успешно проходите через комнату.\n";
        currentLocation = 5;
        return true;
    } else if (strcmp(move, "наступить на плиты") == 0 && currentLocation == 4) {
        std::cout << "Вы наступаете на плиты, и активируется ловушка. Вы теряете одну жизнь.\n";
        lives--;
        if (lives > 0) {
            return true;
        } else {
            std::cout << "Вы погибли. Конец игры.\n";
            return false;
        }
    } else {
        std::cout << "Неверная команда. Попробуйте снова.\n";
        return true;
    }
}

// Отображение инвентаря игрока
void displayInventory() {
    
    std::cout << "Ваш инвентарь:\n";
    for (int i = 0; i < MAX_INVENTORY_ITEMS; ++i) {
        if (strlen(inventory[i]) > 0) {
            std::cout << "- " << inventory[i] << std::endl;
        }
    }
}
