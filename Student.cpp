#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : id(0), name(""), grade(0) {}

Student::Student(int i, string n, float g) : id(i), name(n), grade(g) {}

void Student::display() {
    cout << "ID: " << id << " Name: " << name << " Grade: " << grade << endl;
}
