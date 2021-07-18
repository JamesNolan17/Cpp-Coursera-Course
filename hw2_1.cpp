#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>

using namespace std;
int main()
{
    class Student{
    private:
        string name;
        int age;
        string ID;
        int year1_grade;
        int year2_grade;
        int year3_grade;
        int year4_grade;
        int all_year_avg_grade;
    public:
        explicit Student(string init_cmd){
            string delimiter = ",";
            long pos;
            string token;
            for (int i = 0; i <= 6; i++){
                pos=init_cmd.find(delimiter);
                token = init_cmd.substr(0,pos);
                switch(i){
                    case 0:
                        name = token;
                    case 1:
                        age = atoi(token.c_str());
                    case 2:
                        ID = token;
                    case 3:
                        year1_grade = atoi(token.c_str());
                    case 4:
                        year2_grade = atoi(token.c_str());
                    case 5:
                        year3_grade = atoi(token.c_str());
                    case 6:
                        year4_grade = atoi(token.c_str());
                        all_year_avg_grade = (year1_grade + year2_grade + year3_grade + year4_grade)/4;
                }
                init_cmd.erase(0,pos + delimiter.length());
            }
            cout << name << ',' << age << ',' << ID << ',' << all_year_avg_grade << endl;
        }
    };
    string init_cmd;
    cin >> init_cmd;
    Student* s = new Student(init_cmd);
    delete s;
    return 0;
}