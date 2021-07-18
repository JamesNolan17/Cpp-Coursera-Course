#include <iostream>
using namespace std;

//Function reload
int Max(double f1, double f2) { return 0; }

int Max(int n1, int n2) { return 0; }

int Max(int n1, int n2, int n3) { return 0; }

class A {
public:
    int func(int a) { return a * a; }
};

int main() {
    Max(1.1, 2.2); //1
    Max(1, 2); //2
    //Max(3,2.4); error 二义性
    printf("%d\n", 34 & 27);
    printf("%x\n",-12 >> 2 );
    printf("%d\n",26 | 14);
    printf("%d\n",18 ^ 22);
    int a = 3, b = 5;

    int & r = a;
    r = b;
    b = 7;
    cout << a << endl;


    A aaa; aaa.func(5);
    A * p = new A; p->func(5);
    A & rr = aaa; rr.func(5);

    class Q { int v; };
    Q q; q.v = 3; return 0;
}


int main2() {
    int n, m;
    const int *p = &n; //Const pointer
    // *p = 5; fail tp compile
    n = 4;
    p = &m; //P can change point to others

    const int *p1;
    int *p2;
    p1 = p2;
    //p2 = p1; error
    p2 = (int *) p1; //force casting

    int nn;
    const int &r = n;
    //r = 5; error, cannot use const
    n = 4;

    //Dynamic memory allocation
    int *pn;
    pn = new int;
    *pn = 5;

    int *pnn;
    int i = 5;
    pnn = new int[i * 20];
    pn[0] = 20;
    pn[99] = 20;
    pn[100] = 20; //No error when compiling, got error in execution

    delete pn;
    delete[] pnn;
    //the pointer we del must point to a dynamic memory sapce


    return 0;
}

inline void MyPrintf(const char *p) {
    //strcpy(p,"this");
    //candidate function not viable: 1st argument ('const char *') would lose const qualifier
    printf("%s", p);
}

int defaultParameters(int n, int k = 1, int m = 2) { return 0; }

class CRectangle {
public:
    int w, h;

    void Init(int w_, int h_) {
        w = w_;
        h = h_;
    }

    int Area() { return w * h; }

    int Perimeter() { return 2 * (w + h); }

};

int main_(){
    int w,h;
    CRectangle r;
    cin>>w>>h;
    r.Init(w,h);
    r.w = 5;
    cout<<r.Area()<<endl<<r.Perimeter();


    CRectangle r1, r2;
    CRectangle *p1 = & r1;
    CRectangle *p2 = & r2;
    r1.w = 1;
    r2.h = 2;
    p1->w = 5;
    p2->Init(3,4);




    return 0;
}

class CEmployee{
private:
    char szName[30];
public:
    int salary;
    void setName(char* name);
    void getName(char* name);
};

void CEmployee::setName(char *name) {
    strcpy(szName, name);
}

void CEmployee::getName(char *name) {
    strcpy(name,szName);
}