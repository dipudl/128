#include <iostream>
#include "game.h"

int main()
{
    Game game;

    try
    {
        game.run();
    }
    catch(const char* e)
    {
        std::cout << e << endl;
    }
    catch(...) // Catching all exception
    {
        std::cout << "An unexpected error occurred. Please try again!" << endl;
    }

    return 0;
}
