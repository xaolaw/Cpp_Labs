#include "shapecomposite.h"

Shapes::ShapeComposite::ShapeComposite(shared_ptr<Shape> s1, shared_ptr<Shape> s2,ShapeOperation operation) {
    this->operation_=operation;
    this->shape1=s1;
    this->shape2=s2;
}

bool Shapes::ShapeComposite::isIn(int x, int y) const {
    switch (operation_) {
        case SUM:
            if (this->shape1.get()->isIn(x,y) || this->shape2.get()->isIn(x,y)){
                return true;
            }
            break;
        case INTERSECTION:
            if (this->shape1.get()->isIn(x,y) && this->shape2.get()->isIn(x,y)){
                return true;
            }
            break;
        case DIFFERENCE:
            if (this->shape1.get()->isIn(x,y) && !this->shape2.get()->isIn(x,y)){
                return true;
            }
            break;
    }
    return false;
}

