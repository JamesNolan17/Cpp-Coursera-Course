#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) {
        real = r;
        imag = i;
    }

    double real;
    double imag;

    Complex operator-(const Complex operand2) {
        return Complex(real - operand2.real, imag - operand2.imag);
    }
};

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

class String {
private:
    char *str;
public:
    String() : str(NULL) {}
    //avoid s1 = hello; string s2(s1); causing shallow copy
    String(String &s){
        if(s.str){
            str = new char[strlen(s.str)+1];
            strcpy(str,s.str);
        }else{
            str = NULL;
        }
    }

    const char *c_str() { return str; };

    char *operator=(const char *s);

    ~String();

    //deep copy (have bug when s = s)
    String &operator=(const String &s) {
        if (str == s.str) return *this; //avoid self-copy bug.
        if (str) delete[] str;
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
        return *this;
    }
};

char *String::operator=(const char *s) {
    if (str) delete[] str;
    if (s) { //s != NULL
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    } else {
        str = nullptr;
    }
    return str;
}

String::~String() {
    if (str) delete[] str;
}

int main() {
    Complex a(1, 2), b(2, 3), c, d;
    c = a + b;
    d = a - b;
    cout << c.real << c.imag << endl;
    cout << d.real << d.imag << endl;

    String s, s1, s2;
    s = "Good Luck";
    s1 = "GG";
    s2 = "No";
    cout << s.c_str() << endl;
    s = s1 = s2;
    cout << s.c_str() << endl;
    // String s2 = "hello";  this line is not corrrect because we don't have that constructor yet.

    return 0;
}