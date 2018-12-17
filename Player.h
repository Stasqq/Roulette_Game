//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_PLAYER_H
#define ROULETTE_PROI_V2_PLAYER_H

#include "Bet.h"
#include "CyclicList.h"
#include "Component.h"

class Player {
private:
    CyclicList<Bet> bets;
    int money;
public:
    explicit Player(int);
    void addBet(int,enum betType);
    void addBet(int,enum betType,int*,int);
    void checkBet(Bet*,Component*);
    void checkBets(Component*);

    int getMoney();
    void addMoney(int);
};


#endif //ROULETTE_PROI_V2_PLAYER_H
