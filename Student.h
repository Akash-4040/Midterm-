=#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    float grade;

    Student();
    Student(int i, string n, float g);
    void display();
};

#endif
