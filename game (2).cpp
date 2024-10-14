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
    "(Доп)Закрепить механизм",
    "Вы в сокровищнице. Перед вами пьедестал с реликвией.",
    "Вы заметили скрытый проход в дальней части сокровищницы. Зайдя туда, вы видете нажимные плиты на полу"
};

int lives = 3;
bool researched = 0;

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
    if (researched = 1) {
        std::cout << addLocations[locationIndex] << std::endl;
    }
    
}

// Обработка хода игрока
bool processMove(char* move, int& currentLocation) {
    if (strcmp(move, "инвентарь") == 0) {
        displayInventory();
    } else if (strcmp(move, "уйти") == 0 && currentLocation == 0) {
        std::cout << "Вы решили уйти. Конец игры.\n";
        return false;
    } else if (strcmp(move, "ответить") == 0 && currentLocation == 0) {
        std::cout << "Сфинкс открывает дверь в храм. Вы можете пройти внутрь.\n";
        currentLocation++;
        return true;
    } else if (strcmp(move, "осмотреться") == 0 && currentLocation == 1) {
        std::cout << "Вы заметили чьи-то останки слева от входа. Возле них что-то блестит.\nПодойдя к ним, вы увидели кинжал и взяли его. [Предмет добавлен в инвентарь]";
        researched = 1;
        inventory[2] = "кинжал";
        return true;
     } else if (strcmp(move, "подойти") == 0 && currentLocation == 1) {
        std::cout << "Вы приблизились к мосту. Его удерживает механизм, который выглядит расшатанным. Его следует чем-то закрепить, чтобы мост вдруг не рухнул.";
        return true;
     } else if ((strcmp(move, "закрепить") == 0 or strcmp(move, "веревка") == 0) && currentLocation == 1) {
        std::cout << "Вы решаете закрепить механизм, используя веревку. Теперь можно не волноваться, что мост рухнет";
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
