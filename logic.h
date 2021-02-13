#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <conio.h>

#define SIZE 4
#define INIT_VALUE 2
#define VICTORY_VALUE 128
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class Logic {
protected:
    int numbers[SIZE][SIZE] = {{0}};
    int currentKey, score = 0;
    bool moved = true;
};
