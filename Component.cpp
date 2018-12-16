//
// Created by Stasiek on 2018-12-16.
//

#include "Component.h"

Component::Component() {
    value=0;
    color="none";
}

int Component::getValue() const {
    return value;
}

std::string Component::getColor() const {
    return color;
}

void Component::setValue(int value) {
    Component::value = value;
}

void Component::setColor(std::string color) {
    Component::color = std::move(color);
}