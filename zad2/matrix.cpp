#include <iostream>
#include <string>
#include <iosfwd>
using namespace std;

#include "matrix.h"

TwoDimensionMatrix ::TwoDimensionMatrix() {
    for (int i=0;i<2;i++){
        for (int j=0;j<2; j++){
            matrix[i][j]=0;
        }
    }
}
TwoDimensionMatrix ::TwoDimensionMatrix(const MatrixElement matrix2[size][size]) {
    for (size_t i=0;i<2;i++){
        for (size_t j=0;j<2; j++){
            matrix[i][j] = matrix2[i][j];
        }
    }
}
TwoDimensionMatrix& TwoDimensionMatrix :: operator *= (MatrixElement number) {
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            MatrixElement test1=this->get(i,j);
            this->matrix[i][j]=test1*number;
        }
    }
    return *this;
}
TwoDimensionMatrix TwoDimensionMatrix :: operator + (const TwoDimensionMatrix& obj) const{
    TwoDimensionMatrix temp;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            MatrixElement test1=this->get(i,j),test2=obj.get(i,j);
            temp.matrix[i][j]=test1+test2;
        }
    }
    return temp;
}
TwoDimensionMatrix TwoDimensionMatrix :: operator && (const TwoDimensionMatrix& obj) const{
    TwoDimensionMatrix temp;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            MatrixElement test1=this->get(i,j),test2=obj.get(i,j);
            temp.matrix[i][j]=test1 && test2;
        }
    }
    return temp;
}


MatrixElement* TwoDimensionMatrix :: operator[](size_t i){
    return matrix[i];
}

const MatrixElement* TwoDimensionMatrix::operator[](size_t i) const {
    return matrix[i];
}

istream &operator>>(istream &input, TwoDimensionMatrix &D) {
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            input >> D[i][j];
        }
    }
    return input;
}

ostream &operator<<(ostream &output, const TwoDimensionMatrix &D) {
    output << D.get(0,0) << D.get(0,1) << D.get(1,0) << D.get(1,1);
    return output;
}

TwoDimensionMatrix& TwoDimensionMatrix::operator=(const TwoDimensionMatrix &sample) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrix[i][j] = sample[i][j];
        }
    }
    return *this;
}








