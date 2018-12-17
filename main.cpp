#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Game.h"
#include <windows.h>
int main() {
    srand(0);
    Game g;
    g=Game();
    g.run();
    return 0;
}