#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd

#include "fraction.h"

Fraction::Fraction(int num, int dem) : numerator_(num),denominator_(dem){
    this->numerator_=num;
    if (dem==0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    this->denominator_=dem;
}
Fraction Fraction::operator+(Fraction fraction1) const {
    int denominator=std::lcm(this->denominator_,fraction1.denominator());
    int numerator;
    if (denominator==this->denominator_){
        numerator=fraction1.numerator_+this->numerator_;
    }
    else{
        numerator=fraction1.numerator_*this->denominator_+fraction1.denominator_*this->numerator_;
    }
    int test= std::gcd(numerator,denominator);
    Fraction toReturn(numerator/test,denominator/test);
    return toReturn;
}
Fraction Fraction :: operator*(Fraction fraction1) const{
    int numerator=this->numerator_*fraction1.numerator(),
    denominator=this->denominator_*fraction1.denominator();
    int test= std::gcd(numerator,denominator);
    Fraction toReturn(numerator/test,denominator/test);
    return toReturn;
}

void Fraction::setDenominator(int newDenominator) {
    if (newDenominator==0){
        throw std::invalid_argument("Denominator cannot be 0");
    }
    else{
        this->denominator_=newDenominator;
    }
}
