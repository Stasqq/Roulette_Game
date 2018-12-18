//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_GAME_H
#define ROULETTE_PROI_V2_GAME_H

#include "Roulette.h"
#include "CyclicList.h"
#include "Component.h"
#include "Player.h"
#include "Tests.h"

#include <iostream>
#include <string>

class Game {
private:
    int playersNumber;
    Roulette roulette;
    CyclicList<Player> players;
public:
    Game();

    int printMenu();

    void menuSwitch(int);

    void run();

    void rouletteSpin();

    void addPlayer();

    void addBet();

    void showMoney();

    void showBets();

    void deletePlayer();

    void deleteBet();

    void load();

    void save();
};

#endif //ROULETTE_PROI_V2_GAME_H
