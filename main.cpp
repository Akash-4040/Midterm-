#include <iostream>
#include <string>
#include "Student.h"
#include "GradeBook.h"
using namespace std;

int main() {
    GradeBook gb;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Show All\n3. Search by ID\n4. Save\n5. Load\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) gb.addStudent();
        else if (choice == 2) gb.displayAll();
        else if (choice == 3) {
            int id;
            cout << "ID: "; cin >> id;
            int i = gb.binarySearch(id);
            if (i != -1) gb.showStudent(i);
            else cout << "Not found.\n";
        }
        else if (choice == 4) gb.saveToFile("students.txt");
        else if (choice == 5) gb.loadFromFile("students.txt");
    } while (choice != 0);

    return 0;
}
