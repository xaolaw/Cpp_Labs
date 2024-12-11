#include <iostream>
#include <sstream>
#include "zad5/myList.h"
#include "zad5/mySorting.h"
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <string>
#include <string.h>
#include <cmath> /// sin(), floor()
#include <memory>
#include <vector>
#include <algorithm> // std::count_if
#include <type_traits> // std::is_same<>
#include <functional> // std::bind2nd, std::bing, std::not_equal_to
#include <cctype> // isspace
#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm> // std::copy, std::sort
#include<list>
#ifndef M_PI
constexpr double M_PI = 3.1415926;
#endif
using namespace  std;
template<typename T>
struct MyListTestWrapper : public MyList<T>
{
    using typename MyList<T>::Node;
    using MyList<T>::head;
};



int main(){

    char randomGermanNames[][20] = { "MARLON", "OLAF", "MANFRED", "URS", "THEOPHILUS", "TORSTEN", "UDO", "MORITZ", "VIET", "RAINER", "OLIVER", "OSCAR", "WILBUR", "OLE", "YANNICK", "ZOLTHAR", "OSKAR", "UWE", "XAVER", "WIM", "MALTE", "RUDI", "OLLI", "WILMAR", "PASCAL", "OTTO", "MARTIN", "NOAH", "ULLI", "MIKA", "SVEN", "TORBEN", "WILFRIED", "MATHIS", "WILIBALD", "ROLF", "WILHELM", "MARVIN", "WALTER", "WOLF", "WILLY", "NIELS", "MADS", "MATTHIAS", "TEO", "VOLKER", "ROTGIER" };
    constexpr char sortedGermanNames[][20] = { "MADS", "MALTE", "MANFRED", "MARLON", "MARTIN", "MARVIN", "MATHIS", "MATTHIAS", "MIKA", "MORITZ", "NIELS", "NOAH", "OLAF", "OLE", "OLIVER", "OLLI", "OSCAR", "OSKAR", "OTTO", "PASCAL", "RAINER", "ROLF", "ROTGIER", "RUDI", "SVEN", "TEO", "THEOPHILUS", "TORBEN", "TORSTEN", "UDO", "ULLI", "URS", "UWE", "VIET", "VOLKER", "WALTER", "WILBUR", "WILFRIED", "WILHELM", "WILIBALD", "WILLY", "WILMAR", "WIM", "WOLF", "XAVER", "YANNICK", "ZOLTHAR" };


    mySort(randomGermanNames);
    for(int i=0;i<47;i++){
        cout<<randomGermanNames[i]<<endl;
    }
    return 0;
}





