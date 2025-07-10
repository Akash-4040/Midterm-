#pragma once
#include "Student.h"

class GradeBook {
    Student* students;
    int size, capacity;
    void resize(), sortStudents();
public:
    GradeBook();
    ~GradeBook();
    void addStudent(), displayAll(), showStudent(int i);
    void saveToFile(string f), loadFromFile(string f);
    int binarySearch(int id);
};
