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

    void valueX(int val) { x = val; };

    int valueX() { return x; }
    //avoid 2 meanings
    //void valueX(int val=0){x = val};
    //int valueX(){return x;}
};



class Complex {
public:
    double real, imag;
    Complex(double real, double imag = 0);
    Complex(Complex c1, Complex c2);
    Complex(const Complex& c1);
    Complex();
};

Complex::Complex() {
    real = 0;
    imag = 0;
    cout << "Constructor 1" << endl;
}

Complex::Complex(Complex c1, Complex c2) {
    real = c1.real + c2.real;
    imag = c1.imag + c2.imag;
    cout << "Constructor 1" << endl;
}

Complex::Complex(double real, double imag) {
    this->real = real;
    this->imag = imag;
    cout << "Constructor 2" << endl;
}

Complex::Complex(const Complex& c){
    real = c.real;
    imag = c.imag;
    cout << "Copy Constructor Called" << endl;
}
void Func(Complex aq){}
Complex Func2(){
    Complex b(4);
    return b; //return a new Complex built by copy constructor of Complex
}

class Trans{
public:
    double real, imag;
    Trans(int i){
        cout << "IntConstructor called" << endl;
        real = i;
        imag = 0;
    }

    Trans(double r, double i){
        real = r;
        imag = i;
    }

};

class Destructor{
private:
    char * p;
public:
    Destructor(){
        p = new char[10];
    }
    ~Destructor();
};

Destructor::~Destructor() {
    delete[] p;
    cout << "Destructor called" << endl;
}


class Static{
private:
    int w, h;
    static int nTotalArea; //static variable
    static int nTotalNumber;
public:
    Static(Static &r);
    Static(int w_, int h_);
    ~Static();
    static int PrintTotal(); //static function
};

Static::Static(int w_, int h_){
    w = w_;
    h = h_;
    nTotalNumber ++;
    nTotalArea += w*h;
}

Static::~Static(){
    nTotalNumber --;
    nTotalArea -= w*h;
}
int Static::PrintTotal(){
    cout << nTotalNumber << endl;
    return nTotalNumber;
}

Static::Static(Static &r){
    w = r.w;
    h = r.h;
    nTotalNumber ++;
    nTotalNumber += w*h;
}

//Must initialize them first
int Static::nTotalNumber = 0;
int Static::nTotalArea = 0;

class CEngine{  };
class Ctyre{
private:
    int radius;
    int width;
public:
    Ctyre(int r, int w): radius(r),width(w){ }
};

class CCar;

class CDriver{
public:
    void ModifyCar(CCar * pCar);
};

class CCar{
private:
    int price;
    Ctyre tyre;
    CEngine engine;
public:
    CCar(int p, int tr, int tw);
    friend void CDriver::ModifyCar(CCar *pCar); //friend function
    friend class CDriver; //friend class
};

//Init list
CCar::CCar(int p, int tr, int w):price(p),tyre(tr,w){};

void CDriver::ModifyCar(CCar *pCar) {
    pCar->price += 1000;
}

//This pointer
class Comp{
public:
    double real, imag;
    void Print(){ cout << real << "," << imag << endl; }
    Comp(double r, double i):real(r),imag(i){}
    Comp AddOne() {
        this->real++;
        this->Print();
        return *this;
    }
};

class A{
    int i;
public:
    void Hello() { cout << "hello" << endl; }
};

class B{
    int i;
public:
    void Hello() { cout << i << "hello" << endl; }
};

class ConstObj{
private:
    int value;
public:
    void SetValue(){  } const; //cannot modify value's value. cannot call non-const function.
};

int main() {
    //Complex cl; ERROR
    //Complex * pc = new Complex; ERROR
    Complex cl(2);
    Complex c1(2,4);
    Complex * pc = new Complex(3,4);
    Complex array1[2]; //no args
    Complex array2[6] = {3,3}; //0: 4. 1: 5
    Complex array3[2] = {3};  //0: 3, 1: no args
    Complex * array4 = new Complex[2]; //no args
    delete []array4;

    Complex array5[3] = { 1, Complex(1,2) }; //1 2 3
    Complex *pArray[3] = { new Complex(4), new Complex(1,2)};

    //Copy Constructor
    Complex c2(c1); //Will use default if undefined.

    //Use C1 to initialize C2
    Complex c6(c1); // = Complex c6 = c1 <- Call constructor
    Complex &c7 = c1; // this will not invoke the constructor

    Complex a2;
    Func(a2); //here will use copy constructor to init the Complex
    cout << Func2().real << endl;

    Complex CC1, CC2;
    CC1 = CC2; //Will not call the copy Constructor

    Trans cC1(7,8);
    Trans cC2 = 12; //This is initialization instead of value assignment.
    cC1 = 9; //This one is assignment. 9 is transfered into a temporary object
            // by calling the type-transform-constructor, then assign to cC1.
    Destructor array[2];
    cout << "End" << endl;
    //Print End Destructor Called Destructor Called
    Destructor * des;
    des = new Destructor; //Call constructor
    delete des; //Call destructor
    des = new Destructor[3]; //Call constructor 3 times.
    delete []des; //Call destructor 3 times.

    //Scope, once outside the scope, d5 will be destroyed.
    { Destructor d5(); }
    static int i = 1; //Will only be destroyed when main ends.


    //Static 4 ways
    Static::PrintTotal();

    Static c(1,1);
    c.PrintTotal();

    Static *cc = &c;
    cc->PrintTotal();

    Static & ref = c;
    int n = ref.PrintTotal();

    //Enclosed class
    CCar(100,200,300);

    //This pointer
    Comp ke1(1,1), ke2(0,1);
    ke2 = ke1.AddOne();

    A *p = NULL;
    p->Hello(); //Normal output just the same as straightly calling this function.
    //p->Hello();  ->  Hello(p); then p is not used.


    B *pp = NULL;
    pp->Hello(); //Invalid output
    //p->Hello();  ->  Hello(p); then p is used. so NullPointerException.

    const ConstObj Obj{};

    void PrintObj(ConstObj &o);
    //^Here avid using copy constructor, use const ConstObj &o to avoid o being modified.

    return 0;
}
