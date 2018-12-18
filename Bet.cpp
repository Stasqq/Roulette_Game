//
// Created by Stasiek on 2018-12-16.
//

#include "Bet.h"

Bet::Bet(){
    bt=red;
    howMuch=0;
}

Bet::Bet(enum betType t, int howMuch) {
    bt=t;
    Bet::howMuch=howMuch;
    tab= nullptr;
    numberOfFields=0;
}

Bet::Bet(enum betType t, int *numbers, int howMuch, int numberOfFields) {
    bt=t;
    tab=numbers;
    std::cout<<tab[0]<<tab[1]<<tab[2]<<std::endl;
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

void Bet::saveToFile(std::fstream* file) {
    *file<<bt<<"\n";
    *file<<howMuch<<"\n";
    if(tab != nullptr){
        *file<<numberOfFields<<"\n";
        for(int i=0;i<numberOfFields;i++){
            *file<<tab[i];
            if(i != numberOfFields-1)
                *file<<" ";
        }
    }
    *file<<"\n";
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

int Bet::getNumberOfFields(){
    return numberOfFields;
};