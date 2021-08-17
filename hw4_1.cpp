#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
class Complex {
private:
    double r,i;
public:
    void Print() {
        cout << r << "+" << i << "i" << endl;
    }
    // 在此处补充你的代码
    void operator=(string init_string){
        int pos = init_string.find("+",0);
        string sTmp = init_string.substr(0,pos);
        r = atof(sTmp.c_str());
        sTmp = init_string.substr(pos+1,init_string.length()-pos-2);
        i = atof(sTmp.c_str());
    }
};
int main() {
    Complex a;
    a = "3+4i"; a.Print();
    a = "5+6i"; a.Print();
    return 0;
}