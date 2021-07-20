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

    friend Complex operator+(double r, const Complex &c);
};

Complex operator+(double r, const Complex &c) {
    return Complex(c.real + r, c.imag);
}

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

class CArray{
    int size; //Number of elements in list
    int *ptr; //point to the start address of dynamic allocate list
public:
    CArray(int s = 0); //s stands for the elements in the list
    CArray(CArray & a);
    ~CArray();
    void push_back(int v); //add an element v at the end of the list
    CArray & operator=(const CArray &a); //assign
    int length() {return size;} //return the number of elements in the list
    int & operator[](int i) {  //support n = a[i] and a[i] = 4
        return ptr[i]; //return value of a non-reference function cannot serve as the left value of =
    }
};

CArray::CArray(int s):size(s){
    if (s == 0) ptr = nullptr;
    else ptr = new int[s];
}

CArray::CArray(CArray &a){
    if (!a.ptr){
        ptr = nullptr;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size); //take note
    size = a.size;
}

CArray::~CArray(){
    if (ptr) delete[] ptr;
}

CArray &CArray::operator=(const CArray &a){
    if (ptr == a.ptr) return *this;
    if (a.ptr == nullptr){
        if (ptr) delete[] ptr;
        ptr = nullptr;
        size = 0;
        return *this;
    }
    if (size < a.size){ //if the original array is big enough, no need to allocate
        if (ptr) delete[] ptr;
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

//Low efficiency
void CArray::push_back(int v) {
    if (ptr){
        int *tmpPtr = new int[size+1];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete [] ptr;
        ptr = tmpPtr;
    }else{
        ptr = new int[1];
    }
    ptr[size++] = v;
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
    (s = s1) = s2;
    cout << s.c_str() << endl;
    // String s2 = "hello";  this line is not correct because we don't have that constructor yet

    //Start of length changeable list
    CArray aa;
    for (int i = 0; i < 5; i++) {
        aa.push_back(i);
    }
    CArray a2, a3;
    a2 = aa;
    for (int i = 0; i < 5; i++){
        cout << a2[i] << " ";
    }
    a2 = a3;
    for (int i = 0; i < a2.length(); i++) {
        cout << a2[i] << " ";
    }
    cout << endl;
    aa[3] = 100;
    CArray a4(aa);
    for (int i = 0; i < a4.length(); i++){
        cout << a4[i] << " ";
    }
    //End of length changeable list

    return 0;
}