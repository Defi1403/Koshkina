#include <iostream>
#include <cstring>
#include "game.h"

const char* inventory[MAX_INVENTORY_ITEMS] = {"веревка", "зажигалка", nullptr, nullptr};
const char* locations[MAX_LOCATIONS] = {
    "\nПеред вами храм. Снаружи сидит Сфинкс.\nСфинкс предлагает вам ответить на вопрос.\nВарианты действий:\n- Ответить\n- Уйти",
    "\nВы находитесь в просторном помещении. Перед вами висит мост над оврагом\nВарианты действий:\n- Пройти по мосту на другую сторону\n- Обыскать помещение\n- Взглянуть на механизм",
    "\nВы в сокровищнице. Перед вами пьедестал с реликвией.\nВарианты действий:\n- Взять реликвию\n- Осмотреть пьедестал\n- Пройти дальше",
    "\nВы в сокровищнице. Пьедестала здесь больше нет\nВарианты действий:\n- Пройти дальше",
    "\nВы зашли в небольшую комнатку. Свет из потолка освещает только низ. Вам видны нажимные плиты на полу.\nВарианты действий:\n- Наступить на одну из плит\n- Осветить комнату\n- Вернуться в сокровищницу"
};
const char* addLocations[MAX_LOCATIONS] = {
    nullptr,
    "(Доп)Закрепить механизм",
    "(Доп)Подменить реликвию",
    nullptr,
    "(Доп)Придерживаться последовательности"
};

int lives = 3;
int fixed = 0;


void displayIntro() {
    std::cout << "Добро пожаловать в игру 'Время исследований'!\n";
    std::cout << "Вы начинающий искатель приключений. В вашем инвентаре веревка и зажигалка. Получиться ли у вас успешно преодолеть свое первую экспедицию?\n";
}

void displayCurrentLocation(int locationIndex) {
    std::cout << locations[locationIndex] << std::endl;
}

void displayAdditionalLocation(int locationIndex, int condition) {
    if (locationIndex == condition) {
        std::cout << addLocations[locationIndex] << std::endl;
    }
}

bool processMove(char* move, int& currentLocation, int& addCond) {
    if (strcmp(move, "инвентарь") == 0 or strcmp(move, "открыть") == 0) {
        displayInventory();
        return true;
    } else if (strcmp(move, "уйти") == 0 && currentLocation == 0) {
        std::cout << "Вы осознали, что пусть искателя приключений не для вас, и решили вернуться домой. Спустя годы, вы иногда вспоминаете этот день, жалея, что даже не попробывали испытать себя." << std::endl;
            std::cout << "|Получена скучная концовка|" << std::endl;
            return false;
    } else if (strcmp(move, "ответить") == 0 && currentLocation == 0) {
        std::string answer;
        while (true) {
            std::cout << "Кто ходит на четырех ногах утром, на двух днем и на трех вечером?" << std::endl;
            std::cin >> answer;
            if (answer == "Человек" || answer == "человек") {
                std::cout << "\nСфинкс открывает проход и пропускает вас. Вы заходите в храм. Сразу после этого проход закрывается. Вам проходите в глубь храма." << std::endl;
                currentLocation = 1;
                return true;
            } else if (answer == "уйти") {
                std::cout << "Вы осознали, что пусть искателя приключений не для вас, и решили вернуться домой. Спустя годы, вы иногда вспоминаете этот день, жалея, что даже не попробывали испытать себя." << std::endl;
                std::cout << "|Получена скучная концовка|" << std::endl;
                return false;
            } else {
                std::cout << "Неправильный ответ. Попробуйте снова или введите 'Уйти' для выхода.\n" << std::endl;
            }
       }
    } else if (strcmp(move, "обыскать") == 0 && currentLocation == 1) {
        if (inventory[2] != "кинжал") {
            std::cout << "Вы заметили чьи-то останки слева от входа. Возле них что-то блестит.\nПодойдя к ним, вы увидели незапылившийся серебрянный кинжал и взяли его. [Предмет добавлен в инвентарь]\n";
            inventory[2] = "кинжал";
        } else {
            std::cout << "Вы уже обыскали помещение." << std::endl;
        }
        return true;
     } else if (strcmp(move, "взглянуть") == 0 && currentLocation == 1) {
        if (inventory[0] != "веревка") {
            std::cout << "Этот механизм удерживает мост. Конструкция выглядит надежно, так как вы ее закрепили." << std::endl;
        } else {
            std::cout << "Этот механизм удерживает мост. Конструкция выглядит ненадежно. Перед тем как идти, лучше убедиться, что мост выдержит.\n";
            addCond = 1;
        }
        return true;
     } else if ((strcmp(move, "закрепить") == 0 or strcmp(move, "веревка") == 0) && currentLocation == 1) {
         if (inventory[0] != "веревка") {
             std::cout << "Вы уже закрепили механизм. Теперь мост точно не рухнет.\n";
         } else {
             std::cout << "Вы решаете закрепить механизм, используя веревку. [Предмет убран из инвентаря]. Теперь мост точно не рухнет.\n";
             fixed = 1;
             inventory[0] = nullptr;
         }
         return true;
    } else if (strcmp(move, "пройти") == 0 && currentLocation == 1) {
        if (fixed == 1) {
            std::cout << "Вы проходите на другую сторону моста. Он ведет в следующую комнату." << std::endl;
            currentLocation = 2;
        } else {
            std::cout << "Вы пытаетесь перейти мост, но он рушится, и вы падаете вниз. Вы теряете одну жизнь.\n";
            lives--;
            std::cout << "Вы встряхнули с себя пыль. Понимая, что отсюда нужно выбираться, вы используете веревку, чтобы забраться на противоположную сторону моста. Забравшись, вы идете дальше.\n";
            inventory[0] = nullptr;
            currentLocation = 2;
        }
        return true;
    } else if (strcmp(move, "осмотреть") == 0 && currentLocation == 2) {
        std::cout << "Вы видите что сверху пьедестала есть нажимная плита. Именно на ней стоит реликвия. Также на нем есть табличка\nОна гласит: 'Равноценный обмен'. Скорее всего, взятие реликвии активирует ловушку.\n";
        if (inventory[2] == "кинжал") {
            addCond = 2;
        }
        return true;
    } else if ((strcmp(move, "подменить") == 0 or strcmp(move, "кинжал") == 0) && currentLocation == 2) {
        if (inventory[3] == "реликвия") {
             std::cout << "Вы уже взяли реликвию.\n";
        } else if (inventory[2] != "кинжал") {
             std::cout << "У вас нет предметов чтобы подменить реликвию.\n";;
        } else {
            std::cout << "Вы подменяете реликвию на кинжал. Ловушка не активируется.[Кинжал убран из инвентаря][Реликвия добавлена в инвентарь]\n";
             inventory[3] = "реликвия";
             inventory[2] = nullptr;
             std::cout << "После этого пьедестал начинает медленно опускаться в пол, как будто его основание уходит вглубь.Вы слышите тихий скрежет, и пьедестал скрывается под полом." << std::endl;
             currentLocation = 3;
        }
        return true;
    } else if (strcmp(move, "взять") == 0 && currentLocation == 2) {
        if (inventory[3] != "реликвия") {
            std::cout << "Вы берете реликвию, и активируется ловушка. Вы теряете одну жизнь.\n";
            lives--;
            inventory[3] = "реликвия";
            std::cout << "После этого пьедестал начинает медленно опускаться в пол, как будто его основание уходит вглубь.Вы слышите тихий скрежет, и пьедестал скрывается под полом." << std::endl;
            currentLocation = 3;
        } else {
            std::cout << "Вы уже взяли реликвию.\n";
        }
        return true;
    } else if (strcmp(move, "пройти") == 0 && (currentLocation == 2 or currentLocation == 3)) {
        std::cout << "Вы пересекаете проход и оказываетесь в следующем помещении.\n";
        currentLocation = 4;
        return true;
    } else if ((strcmp(move, "осветить") == 0 or strcmp(move, "зажигалка") == 0) && currentLocation == 4) {
        std::cout << "Вы используете зажигалку и видите надписи на стенах. На них указана последовательность нажатия на плиты\n";
        addCond = 4;
        return true;
    } else if (strcmp(move, "вернуться") == 0 && currentLocation == 4) {
        std::cout << "Вы возвращаетесь обратно.\n";
        if (inventory[3] == "реликвия") {
            currentLocation = 3;
        } else {
            currentLocation = 2;
        }
        addCond = 1;
        return true;
    } else if (strcmp(move, "наступить") == 0 && currentLocation == 4) {
        std::cout << "Вы наступаете на плиты, и активируется ловушка. Вы теряете одну жизнь.\n";
        lives--;
        if (lives < 0) {
            std::cout << "Вы погибли. А ведь конец приключения был уже так близок.\n";
            std::cout << "|Получена незавершенная концовка|" << std::endl;
            return false;
        }
        return true;
    } else if (strcmp(move, "придерживаться") == 0  && currentLocation == 4) {
        std::cout << "Вы наступаете на плиты, следуя правильной последовательности, и успешно проходите это испытание" << std::endl;
        std::cout << "Обратный проход в сокровищницу закрывается. После противоположная стена начинает медленно уезжать вниз, и открывается проход наружу.\n";
        if (inventory[3] == "реликвия") {
            std::cout << "Вы выходите из храма вместе с реликвией. Поздравляем, вы прошли игру!" << std::endl;
            std::cout << "|Получена счастливая концовка|" << std::endl;
        } else {
            std::cout << "Вы выходите из храма без реликвии. Вы прошли игру, не достигнув истинной цели." << std::endl;
            std::cout << "|Получена обидная концовка|" << std::endl;
        }
        return false;
    } else if (strcmp(move, "веревка") == 0 or strcmp(move, "зажигалка") == 0 or strcmp(move, "кинжал") == 0 or strcmp(move, "реликвия") == 0) { 
        std::cout << "Вы не знаете как использовать этот предмет сейчас\n";
        return true;
    } else {
        std::cout << "Неверная команда. Попробуйте снова.\n";
        return true;
    }
}

void displayInventory() {
    std::cout << "Ваш инвентарь:\n";
    for (int i = 0; i < MAX_INVENTORY_ITEMS; ++i) {
        if (inventory[i] != nullptr) {
            std::cout << "- " << inventory[i] << std::endl;
        }
    }
}
