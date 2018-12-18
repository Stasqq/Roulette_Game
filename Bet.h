//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_BET_H
#define ROULETTE_PROI_V2_BET_H

#include <fstream>
#include <iostream>

enum betType{
    red,black,st18,nd18,even,odd,stDozen,ndDozen,rdDozen,stFour,column,sixLine,cornerBet,line,split,straight
};

class Bet {
private:
    enum betType bt;
    int *tab;
    int howMuch;
    int numberOfFields;
public:
    Bet();
    explicit Bet(enum betType,int); //for first 10 types
    Bet(enum betType,int*,int,int); //for column,sixLine,cornerBet,line,straight,split

    bool checkValue(int);

    void saveToFile(std::fstream*);

    int getType();
    int getHowMuch();
    int* getTab();
    int getNumberOfFields();
};


#endif //ROULETTE_PROI_V2_BET_H