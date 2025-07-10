#pragma once
#include <string>
using namespace std;

class Student {
public:
    int id; string name; float grade;

    Student() { id = 0; name = ""; grade = 0; }
    Student(int i, string n, float g) { id = i; name = n; grade = g; }
    void display() { cout << "ID: " << id << " Name: " << name << " Grade: " << grade << endl; }
};
