#include <iostream>
#include <cstring>

using namespace std;

// 在此处补充你的代码
class Array2 {
public:
    int **a_array;
    Array2(){}
    Array2(int a, int b) {
        a_array = new int *[a];
        for (int i = 0; i < a; ++i)
            a_array[i] = new int[b];
    }

    int* &operator[](int n) {
        return a_array[n];
    }

    int &operator()(int a, int b) {
        return a_array[a][b];
    }
};


int main() {
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;
    b = a;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 4; j++) {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

