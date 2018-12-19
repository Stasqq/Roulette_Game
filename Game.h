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
    int whichPlayer();
public:
    Game();

    int printMenu();

    void menuSwitch(int);

    void run();

    void rouletteSpin();

    void addPlayer(std::string,int);

    void addBet(Player*);

    std::string showMoney(Player*);

    std::string showBets(Player*);

    void deleteBet(Player*);

    void load(std::string);

    void save(Player*);

    void tests();

    int getPlayersNumber();

    CyclicList<Player>* getPlayersList();
};

#endif //ROULETTE_PROI_V2_GAME_H
