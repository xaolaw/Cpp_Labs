#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
namespace Shapes{
class Circle :public Shape{
public:
    explicit Circle(int x, int y,int r);
    [[nodiscard]] bool isIn(int x, int y) const override;
    //gettery
    [[nodiscard]] int x() const { return this->xCenter;};
    [[nodiscard]] int y() const {return yCenter;};
    [[nodiscard]] int getRadius() const {return radius;};
private:
    int xCenter,yCenter,radius;
};
}
#endif