//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_GAME_H
#define ROULETTE_PROI_V2_GAME_H

#include "Roulette.h"
#include "CyclicList.h"
#include "Component.h"
#include "Player.h"

class Game {
private:
    Roulette roulette;
    CyclicList<Player> players;
};


#endif //ROULETTE_PROI_V2_GAME_H
