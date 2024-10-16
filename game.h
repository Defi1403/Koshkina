const int MAX_INVENTORY_ITEMS = 4;
const int MAX_LOCATIONS = 5;

extern const char* inventory[MAX_INVENTORY_ITEMS];
extern const char* locations[MAX_LOCATIONS];
extern int lives;
extern int fixed;

void displayIntro();
void displayCurrentLocation(int locationIndex);
void displayAdditionalLocation(int locationIndex, int condition);
bool processMove(char* move, int& currentLocation, int& addCond);
void displayInventory();
