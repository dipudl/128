#include "logic.h"

using namespace std;

class TextManipulation : public Logic {
    protected:
    // center number text to print in random position
    void centerText(int x, int width = 7) {
        int remWidth = width - getSizeOf(x);
        int rightWidth = remWidth/2;
        int leftWidth = remWidth - rightWidth;

        for(int i=0; i<leftWidth; i++) cout << ' ';

        if(x != 0)
            cout << x;
        else
            cout << ' ';

        for(int i=0; i<rightWidth; i++) cout << ' ';
    }

    int getSizeOf(int x) {
        int xSize = 0;

        do{
            xSize++;
            x /= 10;
        }while(x > 0);

        return xSize;
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
