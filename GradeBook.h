#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include "Student.h"
#include <string>
using namespace std;

class GradeBook {
private:
    Student* students;
    int size;
    int capacity;

    void resize();
    void sortStudents();

public:
    GradeBook();
    ~GradeBook();

    void addStudent();
    void displayAll();
    void showStudent(int i);
    void saveToFile(string filename);
    void loadFromFile(string filename);
    int binarySearch(int id);
};

#endif
