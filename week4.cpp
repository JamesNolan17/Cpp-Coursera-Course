#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

class Complex{
public:
    Complex(double r = 0.0, double i = 0.0){
        real = r;
        imag = i;
    }
    double real;
    double imag;

    Complex operator-(const Complex operand2){
        return Complex(real - operand2.real, imag - operand2.imag);

    }
};

Complex operator+(const Complex &a, const Complex &b){
    return Complex(a.real + b.real, a.imag + b.imag);
}



int main(){
    Complex a(1,2), b(2,3), c, d;
    c = a + b;
    d = a - b;
    cout << c.real << c.imag << endl;
    cout << d.real << d.imag << endl;
}