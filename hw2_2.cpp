#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<string.h>

using namespace std;

class Student{
private:
    char name[40];
    char id[40];
    int age;
    int grades[4];
public:
    void setName(char* name);
    void setId(char* id);
    void setAge(int age);
    void setGrade(int g1, int g2, int g3, int g4);
    int getAverage();
};

void Student::setName(char *name_) {
    strcpy(this->name, name_);
}

void Student::setId(char *Id_) {
    strcpy(this->id, Id_);
}

void Student::setAge(int age_) {
    this->age = age_;
}

void Student::setGrade(int g1, int g2, int g3, int g4){
    this->grades[0] = g1;
    this->grades[1] = g2;
    this->grades[2] = g3;
    this->grades[3] = g4;
}

int Student::getAverage() {
    return (grades[0] + grades[1] + grades[2] + grades[3])/4;
}

int main(){
    char name[40];
    char id[40];
    int age;
    int g1, g2, g3, g4;
    char dl;

    cin.getline(name, 40,',');
    cin >> age >> dl;
    cin.getline(id, 40,',');
    cin >> g1 >> dl >> g2 >> dl >> g3 >> dl >> g4;
    Student s;
    s.setName(name);
    s.setAge(age);
    s.setId(id);
    s.setGrade(g1,g2,g3,g4);
    cout << name << ',' << age << ',' << id << ',' << s.getAverage();

    return 0;
};