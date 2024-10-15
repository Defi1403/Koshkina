#include <iostream>
#include <cstring>
#include "game.h"

const char* inventory[MAX_INVENTORY_ITEMS] = {"веревка", "зажигалка", nullptr, nullptr};
const char* locations[MAX_LOCATIONS] = {
    "\nВы находитесь в лесу. Перед вами храм. Снаружи сидит Сфинкс.\nСфинкс задает вам вопрос: 'Кто ходит на четырех ногах утром, на двух днем и на трех вечером?'\n",
    "\nВы видите мост над пропастью. Что будете делать?",
    "\nВы в сокровищнице. Перед вами пьедестал с реликвией.",
    "\nВы заметили скрытый проход в дальней части сокровищницы. Зайдя туда, вы видете нажимные плиты на полу"
};
const char* addLocations[MAX_LOCATIONS] = {
    "",
    "(Доп)Закрепить механизм",
    "(Доп)Подменить реликвию",
    "(Доп)Придерживаться последовательности"
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

void displayAdditionalLocation(int locationIndex, int condition) {
    if (locationIndex == condition) {
        std::cout << addLocations[locationIndex] << std::endl;
    }
}

// Обработка хода игрока
bool processMove(char* move, int& currentLocation, int& addCond) {
    if (strcmp(move, "инвентарь") == 0) {
        displayInventory();
        return true;
    } else if (strcmp(move, "уйти") == 0 && currentLocation == 0) {
        std::cout << "Вы решили уйти. Конец игры.\n";
        return false;
    } else if (strcmp(move, "ответить") == 0 && currentLocation == 0) {
        std::cout << "Сфинкс открывает дверь в храм. Вы можете пройти внутрь.\n";
        currentLocation++;
        return true;
    } else if (strcmp(move, "осмотреться") == 0 && currentLocation == 1) {
        std::cout << "Вы заметили чьи-то останки слева от входа. Возле них что-то блестит.\nПодойдя к ним, вы увидели кинжал и взяли его. [Предмет добавлен в инвентарь]";
        inventory[2] = "кинжал";
        return true;
     } else if (strcmp(move, "взглянуть") == 0 && currentLocation == 1) {
        std::cout << "Вы смотрите на механизм, который удерживает мост. Конструкция выглядит ненадежно. Перед тем как идти, лучше убедиться, что мост выдержит";
        addCond = 1;
        return true;
     } else if ((strcmp(move, "закрепить") == 0 or strcmp(move, "веревка") == 0) && currentLocation == 1) {
        std::cout << "Вы решаете закрепить механизм, используя веревку. Теперь мост точно не рухнет. Вы проходите по мосту и оказываетесь на другой стороне";
        inventory[0] = nullptr;
        currentLocation = 2;
        return true;
    } else if (strcmp(move, "перейти") == 0 && currentLocation == 1) {
        std::cout << "Вы пытаетесь перейти мост, но он рушится, и вы падаете в пропасть. Вы теряете одну жизнь.\n";
        lives--;
        std::cout << "Вы встряхнули с себя пыль. Понимая, что отсюда нужно выбираться, вы используете веревку, чтобы забраться на противоположную сторону моста";
        inventory[0] = nullptr;
        currentLocation = 2;
        return true;
    } else if (strcmp(move, "осмотреть") == 0 && currentLocation == 2) {
        std::cout << "Вы видите что сверху пьедестала есть нажимная плита. Именно на ней стоит реликвия. Скорее всего, взятие реликвии активирует ловушку\n";
        addCond = 2;
        return true;
    } else if ((strcmp(move, "подменить") == 0 or strcmp(move, "кинжал") == 0) && currentLocation == 2) {
        std::cout << "Вы подменяете реликвию на кинжал. Ловушка не активируется.\n";
        inventory[3] = "реликвия";
        currentLocation = 3;
        std::cout << "Вы видите проход в дальней части сокровищницы. Вы проходите дальше\n";
        return true;
    } else if (strcmp(move, "взять") == 0 && currentLocation == 2) {
        std::cout << "Вы берете реликвию, и активируется ловушка. Вы теряете одну жизнь.\n";
        lives--;
        inventory[3] = "реликвия";
        currentLocation = 3;
        std::cout << "Вы видите проход в дальней части сокровищницы. Вы проходите дальше\n";
        return true;
    } else if ((strcmp(move, "осветить") == 0 or strcmp(move, "зажигалка") == 0) && currentLocation == 3) {
        std::cout << "Вы используете зажигалку и читаете надписи на стенах.\n";
        addCond = 3;
        return true;
    } else if (strcmp(move, "придерживаться") == 0  && currentLocation == 3) {
        std::cout << "Вы выясняете последовательность нажатия на плиты.\n";
        addCond = 3;
        return true;
    } else if (strcmp(move, "наступить") == 0 && currentLocation == 3) {
        std::cout << "Вы наступаете на плиты, и активируется ловушка. Вы теряете одну жизнь.\n";
        lives--;
        if (lives > 0) {
            std::cout << "Вы прошли игру\n";
            return false;
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
        if (inventory[i] != nullptr) {
            std::cout << "- " << inventory[i] << std::endl;
        }
    }
}
