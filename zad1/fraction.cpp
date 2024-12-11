#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#include "fraction.h"


Fraction::Fraction() {
    this->denominator=defaultDenominatorValue;
    this->numerator=0;
}
Fraction::Fraction(int a,int b,string name):fractionName(name) {
    this->denominator=b;
    this->numerator=a;
}
Fraction::Fraction(int a,int b=defaultDenominatorValue) {
    this->denominator=b;
    this->numerator=a;
}
void Fraction::print() const{
    cout<<numerator<<"/"<<denominator<<"\n";
}
int Fraction::removedFractions_=0;
void Fraction::save(std::ostream &os) const {
    os << numerator << "/" << denominator;
}
void Fraction::load(std::istream &is) {
    char temp;
    is >> numerator >> temp >> denominator;
}

/*#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif
#endif // IMPLEMENTED_classFractionExists*/

