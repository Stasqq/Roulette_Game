//
// Created by Stasiek on 2018-12-18.
//

#ifndef ROULETTE_PROI_V2_TESTS_H
#define ROULETTE_PROI_V2_TESTS_H

#include "Roulette.h"
#include "CyclicList.h"
#include "Component.h"
#include "Player.h"
#include "Bet.h"
#include "Game.h"

#include <iostream>
#include <string>

class Tests {
public:
    bool spinTest();

    bool addPlayerTest();

    bool deletePlayerTest();

    bool addBetTest();

    bool deleteBetTest();

    bool showMoneyTest();

    bool saveAndLoadTest();

    bool autonomicTest();
};


#endif //ROULETTE_PROI_V2_TESTS_H
