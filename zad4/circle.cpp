#include "circle.h"
#include <cmath>
#include <iostream>

Shapes::Circle::Circle(int x, int y, int r) {
    this->xCenter=x;
    this->yCenter=y;
    this->radius=r;
}

bool Shapes::Circle::isIn(int x, int y) const {
    float distance=pow(x-xCenter,2)+ pow(y-yCenter,2);
    if (distance<=pow(getRadius(),2)){
        return true;
    }
    return false;
}


