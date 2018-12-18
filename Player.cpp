//
// Created by Stasiek on 2018-12-16.
//

#include "Player.h"

Player::Player() {
    money=0;
    bets=CyclicList<Bet>();
    name=" ";
}

void Player::addBet(int howMuch, enum betType typ) {
    bets.pushBack(Bet(typ,howMuch));
    money -= howMuch;
}

void Player::addBet(int howMuch, enum betType typ, int *numbers,int howMuchNumbers) {
    bets.pushBack(Bet(typ,numbers,howMuch,howMuchNumbers));
    money -= howMuch;
}

void Player::checkBet(Bet *bet, Component *field) {
    int type=bet->getType();
    switch(type){
        case 0:{
            if(field->getColor() == "red"){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 1:{
            if(field->getColor() == "black"){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 2:{
            if(field->getValue() < 19 && field->getValue() != 0){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 3:{
            if(field->getValue() > 18){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 4:{
            if(field->getValue()%2 == 0){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 5:{
            if(field->getValue()%2 == 1){
                money = money + bet->getHowMuch() * 2;
            }
        }break;
        case 6:{
            if(field->getValue() > 0 && field->getValue() < 13){
                money = money + bet->getHowMuch() * 3;
            }
        }break;
        case 7:{
            if(field->getValue() > 12 && field->getValue() < 25){
                money = money + bet->getHowMuch() * 3;
            }
        }break;
        case 8:{
            if(field->getValue() > 24 && field->getValue() < 37){
                money = money + bet->getHowMuch() * 3;
            }
        }break;
        case 9:{
            if(field->getValue() < 4){
                money = money + bet->getHowMuch() * 7;
            }
        }break;
        case 10:{
            if(bet->checkValue(field->getValue())){
                money = money + bet->getHowMuch() * 3;
            }
        }break;
        case 11:{
            if(bet->checkValue(field->getValue())){
                money = money + bet->getHowMuch() * 6;
            }
        }break;
        case 12:{
            if(bet->checkValue(field->getValue())){
                money = money + bet->getHowMuch() * 9;
            }
        }break;
        case 13:{
            if(bet->checkValue(field->getValue())){
                money = money + bet->getHowMuch() * 12;
            }
        }break;
        case 14:{
            if(bet->checkValue(field->getValue())){
                money = money + bet->getHowMuch() * 18;
            }
        }break;
        case 15:{
            if(field->getValue() == bet->getTab()[0]){
                money = money + bet->getHowMuch() * 36;
            }
        }break;
        default:{

        }break;
    }
}

void Player::checkBets(Component* field) {
    if(bets.size() != 0) {
        int nrBet=bets.size();
        for(int i=0;i<nrBet;i++) {
            checkBet(bets.getByIndex(i),field);
        }
    }else{
        return;
    }
}

void Player::clearBets() {
    bets=CyclicList<Bet>();
}

std::string Player::showBets() {
    std::string output;
    if(bets.size() != 0) {
        for(int i=0;i<bets.size();i++){
            output+= std::to_string(i+1) + ". " + std::to_string(bets.getByIndex(i)->getType()+1) + " for " + std::to_string(bets.getByIndex(i)->getHowMuch()) +"\n";
        }
    }else{
        output="You have no bets\n";
    }
    return output;
}

int Player::getMoney() {
    return money;
}

void Player::addMoney(int newMoney) {
    money += newMoney;
}

void Player::setName(std::string x) {
    name=x;
}

std::string Player::getName() {
    return name;
}

