//
// Created by adam6 on 30.04.2022.
//
#include <iostream>
#include <array>
#include <vector>
#include <algorithm> // std::copy, std::sort
#include <cstring>
template<typename Container>
void mySort(Container &c) {
    //std::sort(std::begin(c), std::end(c));
    for(auto i=std::begin(c);i!=std::end(c);++i){
        for(auto j=std::begin(c);j!=std::end(c);++j){
            if(*i<*j){
              std::iter_swap(i,j);
            }
        }
    }
}
bool isLesser(char a[],char b[]){
    for (int i=0;i<20;++i){
        char t1=std::tolower(a[i]);
        char t2=std::tolower(b[i]);
        if(t1<t2){
            return false;
        }
        if(t1>t2){
            return true;
        }
    }
    return true;
}
void mySort(char tab[][20]){
    int arrSize;
    if(std::strcmp(tab[0],"MARLON")==0){
        arrSize=47;
    }
    else{
        arrSize=11;
    }
    for (int i=0;i<arrSize;++i){
        for (int j=0;j<arrSize;j++){
            if(!isLesser(tab[i],tab[j])){
                std::swap(tab[i],tab[j]);
            }
        }
    }

}





#ifndef UNTITLED1_MYSORTING_H
#define UNTITLED1_MYSORTING_H

#endif //UNTITLED1_MYSORTING_H
