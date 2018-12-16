//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_ROULETTE_H
#define ROULETTE_PROI_V2_ROULETTE_H

#include "CyclicList.h"
#include "Component.h"
#include <string>
#include <iostream>
#include <fstream>

class Roulette {
private:
    CyclicList<Component> plate;
public:
    Roulette();
    void printPlate();
};


#endif //ROULETTE_PROI_V2_ROULETTE_H
