#include "rectangle.h"

bool Shapes::Rectangle::isIn(int x, int y) const {
    if (xFrom_<=x && x<=xTo_ && yFrom_<=y && y<=yTo_) {
        return true;
    }
    return false;
}

Shapes::Rectangle::Rectangle(int xFrom, int yFrom,int xTo, int yTo) {
    this->xTo_=xTo;
    this->yTo_=yTo;
    this->xFrom_=xFrom;
    this->yFrom_=yFrom;
}
