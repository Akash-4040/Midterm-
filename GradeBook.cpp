#include <iostream>
#include <fstream>
#include "GradeBook.h"
using namespace std;

GradeBook::GradeBook() { capacity = 5; size = 0; students = new Student[capacity]; }
GradeBook::~GradeBook() { delete[] students; }

void GradeBook::resize() {
    capacity *= 2;
    Student* temp = new Student[capacity];
    for (int i = 0; i < size; i++) temp[i] = students[i];
    delete[] students; students = temp;
}

void GradeBook::sortStudents() {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (students[j].id > students[j + 1].id)
                swap(students[j], students[j + 1]);
}

void GradeBook::addStudent() {
    if (size == capacity) resize();
    int id; string name; float grade;
    cout << "ID: "; cin >> id;
    cout << "Name: "; cin.ignore(); getline(cin, name);
    cout << "Grade: "; cin >> grade;
    students[size++] = Student(id, name, grade);
    sortStudents();
}

void GradeBook::displayAll() {
    for (int i = 0; i < size; i++) students[i].display();
}

void GradeBook::showStudent(int i) { students[i].display(); }

void GradeBook::saveToFile(string f) {
    ofstream file(f);
    for (int i = 0; i < size; i++)
        file << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
    cout << "Saved.\n";
}

void GradeBook::loadFromFile(string f) {
    ifstream file(f); size = 0;
    while (file) {
        int id; string name; float grade;
        file >> id >> name >> grade;
        if (file) {
            if (size == capacity) resize();
            students[size++] = Student(id, name, grade);
        }
    }
    sortStudents();
    cout << "Loaded.\n";
}

int GradeBook::binarySearch(int id) {
    int l = 0, r = size - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (students[m].id == id) return m;
        else if (students[m].id < id) l = m + 1;
        else r = m - 1;
    }
    return -1;
}
