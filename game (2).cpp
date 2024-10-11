#ifndef GAME_H
#define GAME_H

const int MAX_INVENTORY_ITEMS = 3;
const int MAX_LOCATIONS = 4;

extern const char* inventory[MAX_INVENTORY_ITEMS];
extern const char* locations[MAX_LOCATIONS];
extern int lives;

void displayIntro();
void displayCurrentLocation(int locationIndex);
bool processMove(char* move, int& currentLocation, bool& hasDagger);
void displayInventory();

#endif // GAME_H
