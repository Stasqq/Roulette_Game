//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_BET_H
#define ROULETTE_PROI_V2_BET_H

#include <fstream>
#include <iostream>

enum betType{
    red=1,black=2,st18=3,nd18=4,even=5,odd=6,stDozen=7,ndDozen=8,rdDozen=9,stFour=10,column=11,sixLine=12,cornerBet=13,line=14,split=15,straight=16
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