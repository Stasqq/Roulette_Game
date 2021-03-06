//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_PLAYER_H
#define ROULETTE_PROI_V2_PLAYER_H

#include "Bet.h"
#include "CyclicList.h"
#include "Component.h"

#include <cstdlib>
#include <string>

class Player {
private:
    CyclicList<Bet> bets;
    int money;
    std::string name;
public:
    Player();

    void addBet(int, enum betType);

    void addBet(int, enum betType, int *, int);

    void checkBet(Bet *, Component *);

    void checkBets(Component *);

    void clearBets();

    std::string showBets();

    void deleteBet(int);

    int getMoney();

    void addMoney(int);

    void setName(std::string);

    std::string getName();

    int getBetsSize();

    Bet *getBet(int);
};


#endif //ROULETTE_PROI_V2_PLAYER_H
