//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_PLAYER_H
#define ROULETTE_PROI_V2_PLAYER_H

#include "Bet.h"
#include "CyclicList.h"

class Player {
private:
    CyclicList<Bet> bets;
    int money;
};


#endif //ROULETTE_PROI_V2_PLAYER_H
