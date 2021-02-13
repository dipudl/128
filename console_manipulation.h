#include "text_manipulation.h"

using namespace std;

class ConsoleManipulation : public TextManipulation {

protected:
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
                centerText(numbers[i][j]);

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

        // Exception handling
        if(currentKey != KEY_UP &&
            currentKey != KEY_DOWN &&
             currentKey != KEY_RIGHT &&
              currentKey != KEY_LEFT) {
            throw("Unable to determine the pressed key!");
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
