//
// Created by Stasiek on 2018-12-16.
//

#ifndef ROULETTE_PROI_V2_COMPONENT_H
#define ROULETTE_PROI_V2_COMPONENT_H

#include <string>

class Component {
private:
    int value;
    std::string color;
public:
    Component();

    void setValue(int value);

    void setColor(std::string color);

    std::string getColor() const;

    int getValue() const;
};


#endif //ROULETTE_PROI_V2_COMPONENT_H
