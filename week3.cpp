#include <iostream>
using namespace std;

class Inline_Class{
    //These 2 are all inline func
    inline void func1();
    void func2(){};
};

void Inline_Class::func1(){};

class Location{
private:
    int x,y;
};