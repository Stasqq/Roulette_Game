//
// Created by Stasiek on 2018-12-16.
//

#include "Roulette.h"

Roulette::Roulette() {
    plate=CyclicList<Component>();
    std::fstream f;
    f.open("components.txt",std::ios::in);
    if(f.good()) {
        while (!f.eof()) {
            Component newC=Component();
            std::string input;
            getline(f,input);
            newC.setValue(std::stoi(input));
            getline(f,input);
            newC.setColor(input);
            plate.pushBack(newC);
        }
    }else{
        std::cout<< "Wystapil blad przy odczycie pliku" <<std::endl;
    }
}

Component* Roulette::draw() {
    int x=rand()%100;
    return plate.getByIndex(x);
}

void Roulette::printPlate() {
    for(int i=0;i<37;i++){
        std::cout<< plate.getByIndex(i)->getValue() << ", " << plate.getByIndex(i)->getColor() << std::endl;
    }
}