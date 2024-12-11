#include "shape.h"
#include <memory>
using namespace std;
namespace Shapes{
    class ShapeComposite: public Shape{
    public:
        explicit ShapeComposite(shared_ptr<Shape> s1, shared_ptr<Shape> s2,ShapeOperation operation);
        [[nodiscard]] bool isIn(int x, int y) const override;
    private:
        ShapeOperation operation_;
        shared_ptr<Shape> shape1;
        shared_ptr<Shape> shape2;
    };

}

