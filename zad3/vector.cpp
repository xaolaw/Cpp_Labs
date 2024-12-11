// author: Grzegorz Prowadzacy

#include <algorithm>
#include <stdlib.h>
#include <stdexcept>
#include <utility> // std::swap()
#include "vector.h"
#include "fraction.h"


Vector::Vector(const size_t a) : data_(),capacity_(),size_(){
    //data ->tab, capacity-> ile pomiesci, size_ -> ile jest
    this->data_= (Fraction*) calloc(a,sizeof (Fraction));
    this->capacity_=a;
    this->size_=0;
}

Vector::~Vector() {
    delete[] data_;
}

Vector::Vector(const Vector &sample) : capacity_(),size_(),data_() {
    this->capacity_=sample.capacity();
    this->size_=sample.size();
    this->data_=(Fraction*) calloc(this->capacity(),sizeof (Fraction));
    for (size_t i=0;i<this->size();i++){
        this->data_[i]=sample.data_[i];
    }
}

void Vector::push_back(const Fraction toAdd) {
    if (this->capacity()==this->size()){
        this->capacity_++;
        this->data_= (Fraction*) realloc(this->data_,this->capacity_*sizeof (Fraction));
    }
    this->data_[size()]=toAdd;
    this->size_=size()+1;

}
//przenoszącej?
//operator równa się dla reszty
Vector& Vector::operator=(const Vector &sample)   {
    if (&sample!=this){
        Vector tmp(sample);
        std::swap(*this,tmp);
    }
    /*this->size_=std::move(sample.size());
    this->capacity_=std::move(sample.capacity());
    this->data_= (Fraction*) calloc(capacity_,sizeof (Fraction));
    for (size_t i=0;i<sample.size();i++){
        this->data_[i]=sample[i];
    }*/
    return *this;
}

Fraction Vector::operator[](size_t i) {
    if (size()-1<i || size()==0){
        throw std::out_of_range("Out of range");
    }
    return data_[i];
}
Fraction Vector::operator[](size_t i) const {
    if (size()-1<i || size()==0){
        throw std::out_of_range("Out of range");
    }
    return data_[i];
}
//operator równa się dla move
Vector &Vector::operator=(Vector &&val) noexcept {
    {
        std::swap(data_, val.data_);
        std::swap(size_, val.size_);
        std::swap(capacity_, val.capacity_);
    }
    return *this;
}
//move konstruktor
Vector::Vector(Vector &&val) noexcept : data_(val.data_), size_(val.size_),capacity_(val.capacity_){
    val.data_= nullptr;
    val.size_=0;
    val.capacity_=0;
}


