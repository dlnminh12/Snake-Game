#include"header.h"
void GenerateFood(int foodIndex) {
	int x, y;
	srand(time(NULL));
	for (int i = foodIndex; i < MAX_SIZE_FOOD; i++) {
		do {
			x = rand() % (WIDTH_CONSOLE - 3) + 2;
			y = rand() % (HEIGH_CONSOLE - 3) + 2;
		} while (IsValid(x, y) == false);
		food[i] = { x,y };
	}
}
