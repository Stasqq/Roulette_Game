#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include <windows.h>
#include <time.h>

int main() {
    srand(time(NULL));
    Game g;
    g=Game();
    g.run();
    return 0;
}