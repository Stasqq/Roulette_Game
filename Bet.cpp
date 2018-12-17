//
// Created by Stasiek on 2018-12-16.
//

#include "Bet.h"

Bet::Bet(enum betType t, int howMuch) {
    bt=t;
    Bet::howMuch=howMuch;
}

Bet::Bet(enum betType t, int *numbers, int howMuch, int numberOfFields) {
    bt=t;
    tab=numbers;
    Bet::howMuch=howMuch;
    Bet::numberOfFields=numberOfFields;
}

bool Bet::checkValue(int looking) {
    for(int i=0;i<numberOfFields;i++){
        if(tab[i]==looking)
            return true;
    }
    return false;
}

int Bet::getType() {
    return bt;
}

int Bet::getHowMuch() {
    return howMuch;
}

int* Bet::getTab() {
    return tab;
}