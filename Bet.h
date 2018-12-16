//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_BET_H
#define ROULETTE_PROI_V2_BET_H

enum betType{
    red,black,st18,nd18,even,odd,stDozen,ndDozen,rdDozen,stFour,column,sixLine,cornerBet,line,split,straight
};

class Bet {
private:
    enum betType bt;
    int *tab;
public:
    explicit Bet(enum betType); //for first 10 types
    Bet(enum betType,int); //for column,sixLine,cornerBet,line,straight
    Bet(enum betType,int,int); //for split
};


#endif //ROULETTE_PROI_V2_BET_H