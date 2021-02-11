#include "console_manipulation.h"

using namespace std;

class Game: public ConsoleManipulation {
public:
    Game() {
        // for the seed value, providing the time(0) function result
        srand((int) time(0));
        // insert random value at start
        insertRandomValue();
    }

    void run() {
        while(!isGameOver()) {
            // clear console
            printLayout(true);
            insertRandomValue();
            // print game layout
            printLayout();

            if(isGameOver()) break;

            getInput();
            moveNumbers();
        }
    }

protected:
    // insert a random value to one of the blank position after user takes a move
    void insertRandomValue() {
        int randRow, randColumn;
        bool inserted = false;

        if(moved){
            // loop until blank position is found and insert value there
            while(!inserted) {
                randRow = rand() % SIZE;
                randColumn = rand() % SIZE;

                if(numbers[randRow][randColumn] == 0) {
                    numbers[randRow][randColumn] = INIT_VALUE;
                    inserted = true;
                }
            }
        }
    }

    // check if game over or game own
    bool isGameOver() {
        bool gameEnd = true;

        for(int i=0; i<SIZE; i++) {
            for(int j=0; j<SIZE; j++) {
                if(numbers[i][j] == 0) {
                    gameEnd = false;
                }

                // check if a number is equal to VICTORY_VALUE(128)
                // return true if game own
                if(numbers[i][j] >= VICTORY_VALUE) {
                    //clear console
                    printLayout(true);
                    //print game layout
                    printLayout();
                    cout << " Hurray! You won :)" << endl << endl;
                    return true;
                }
            }
        }

        if(gameEnd) {
            cout << " Oops! You lost :(" << endl;
        }

        // return true if game lost
        return gameEnd;
    }
};
