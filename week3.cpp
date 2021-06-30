#include <iostream>

using namespace std;

class Inline_Class {
    //These 2 are all inline func
    inline void func1();

    void func2() {};
};


void Inline_Class::func1() {};

class Location {
private:
    int x, y;
public:
    void init(int x = 0, int y = 0);

    void valueX(int val) { x = val };

    int valueX() { return x; }
    //avoid 2 meanings
    //void valueX(int val=0){x = val};
    //int valueX(){return x;}
};

class Complex {
private:
    double real, imag;
public:
    Complex(double real, double imag = 0);
};

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
}