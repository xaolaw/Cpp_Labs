#include "shape.h"
namespace Shapes
{
class Rectangle :public Shape
{
    public:
        explicit Rectangle(int xFrom,int yFrom,int xTo,int yTo);
        [[nodiscard]] bool isIn(int x, int y) const override;
        //gettery
        [[nodiscard]] int xTo() const {return xTo_;};
        [[nodiscard]] int yTo() const {return yTo_;};
        [[nodiscard]] int x() const {return xFrom_;};
        [[nodiscard]] int y() const {return yFrom_;};

    private:
        int xTo_,yTo_,xFrom_,yFrom_;
};
}