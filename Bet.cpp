//
// Created by Stasiek on 2018-12-16.
//

#include "Bet.h"

Bet::Bet(enum betType t) {
    bt=t;
}

Bet::Bet(enum betType t, int which) {
    bt=t;
}

Bet::Bet(enum betType t, int st, int nd){
    bt=t;
    tab[0]=st;
    tab[1]=nd;
}