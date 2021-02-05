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

using namespace std;

int numbers[SIZE][SIZE] = {0};
int currentKey, score = 0;
bool moved = true;


class TextManipulation {
    public:

    // center number text to print in random position
    void centerText(string x, int width = 7) {
        int remWidth = width - x.size();
        int rightWidth = remWidth/2;
        int leftWidth = remWidth - rightWidth;

        for(int i=0; i<leftWidth; i++) cout << ' ';

        if(x != "0")
            cout << x;
        else
            cout << ' ';

        for(int i=0; i<rightWidth; i++) cout << ' ';
    }

    // move and merge numbers according to user input(up, down, right or left arrow)
    void moveNumbers() {

        moved = false;

        switch(currentKey) {

        case KEY_UP:
            for(int i=0; i<SIZE; i++) {
                for(int j=0; j<SIZE-1; j++) {

                    for(int k=j+1; k<SIZE; k++) {
                        if(numbers[k][i] != 0) {
                            if(numbers[j][i] == 0) {
                                numbers[j][i] = numbers[k][i];
                                numbers[k][i] = 0;
                                moved = true;
                            }else{
                                if(numbers[j][i] == numbers[k][i]) {
                                    numbers[j][i] *= 2;
                                    numbers[k][i] = 0;
                                    moved = true;

                                    score +=  numbers[j][i];
                                }
                                break;
                            }
                        }
                    }

                }
            }
            break;

        case KEY_DOWN:
            for(int i=0; i<SIZE; i++) {
                for(int j=SIZE-1; j>0; j--) {

                    for(int k=j-1; k>=0; k--) {
                        if(numbers[k][i] != 0) {
                            if(numbers[j][i] == 0) {
                                numbers[j][i] = numbers[k][i];
                                numbers[k][i] = 0;
                                moved = true;
                            }else{
                                if(numbers[j][i] == numbers[k][i]) {
                                    numbers[j][i] *= 2;
                                    numbers[k][i] = 0;
                                    moved = true;

                                    score +=  numbers[j][i];
                                }
                                break;
                            }
                        }
                    }

                }
            }
            break;

        case KEY_RIGHT:
            for(int i=0; i<SIZE; i++) {
                for(int j=SIZE-1; j>0; j--) {

                    for(int k=j-1; k>=0; k--) {
                        if(numbers[i][k] != 0) {
                            if(numbers[i][j] == 0) {
                                numbers[i][j] = numbers[i][k];
                                numbers[i][k] = 0;
                                moved = true;
                            }else{
                                if(numbers[i][j] == numbers[i][k]) {
                                    numbers[i][j] *= 2;
                                    numbers[i][k] = 0;
                                    moved = true;

                                    score +=  numbers[i][j];
                                }
                                break;
                            }
                        }
                    }

                }
            }
            break;

        case KEY_LEFT:
            for(int i=0; i<SIZE; i++) {
                for(int j=0; j<SIZE-1; j++) {

                    for(int k=j+1; k<SIZE; k++) {
                        if(numbers[i][k] != 0) {
                            if(numbers[i][j] == 0) {
                                numbers[i][j] = numbers[i][k];
                                numbers[i][k] = 0;
                                moved = true;
                            }else{
                                if(numbers[i][j] == numbers[i][k]) {
                                    numbers[i][j] *= 2;
                                    numbers[i][k] = 0;
                                    moved = true;

                                    score +=  numbers[i][j];
                                }
                                break;
                            }
                        }
                    }

                }
            }
            break;
        }
    }

};

class ConsoleManipulation : public TextManipulation {
public:

    // print layout for the game according to defined SIZE
    void printLayout() {

        cout << " |------------|" << endl;
        cout << " |  " << VICTORY_VALUE << " GAME  |" << endl;
        cout << " |------------|" << endl << endl;

        cout << endl << endl;
        for(int k=0; k<SIZE; k++) {
            cout << "|-------";
        }
        cout << '|' << endl;

        for(int i=0; i<SIZE; i++) {
            cout << "|";

            for(int j=0; j<SIZE; j++) {
                centerText(to_string(numbers[i][j]));

                // don't draw on last column
                cout << "|";
            }

            cout << endl;
            for(int k=0; k<SIZE; k++) {
                cout << "|-------";
            }
            cout << '|' << endl;

        }

        cout << endl << endl;
        cout << " SCORE : " << score;
        cout << endl << endl;
    }

    void getInput() {
        int c;
        bool complete = false;

        // loop until user provides right command (i.e. up, down, right or left arrow)
        while(!complete)
        {
            c = _getch();

            if(c == KEY_UP || c == KEY_DOWN || c == KEY_RIGHT || c == KEY_LEFT) {
                currentKey = c;
                complete = true;
            }

        }
    }

    // clean console or print without cleaning
    // polymorphism (function overloading)
    void printLayout(bool clean) {
        // check operating system of user and execute corresponding system command to clear console
        if(clean) {
            #if defined _WIN32
                system("cls");
            #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                system("clear");
            #elif defined (__APPLE__)
                system("clear");
            #endif
        }
    }
};

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
                    //clear conole
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

int main()
{
    Game game;
    game.run();

    return 0;
}
