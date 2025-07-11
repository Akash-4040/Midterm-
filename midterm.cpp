#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ===== Student Class =====
class Student {
public:
    int id;
    string name;
    float grade;

    Student() : id(0), name(""), grade(0) {}
    Student(int i, string n, float g) : id(i), name(n), grade(g) {}

    void display() {
        cout << "ID: " << id << " Name: " << name << " Grade: " << grade << endl;
    }
};

// ===== GradeBook Class =====
class GradeBook {
private:
    Student* students;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Student* temp = new Student[capacity];
        for (int i = 0; i < size; i++)
            temp[i] = students[i];
        delete[] students;
        students = temp;
    }

    void sortStudents() {
        for (int i = 0; i < size - 1; i++)
            for (int j = 0; j < size - i - 1; j++)
                if (students[j].id > students[j + 1].id)
                    swap(students[j], students[j + 1]);
    }

public:
    GradeBook() : size(0), capacity(5) {
        students = new Student[capacity];
    }

    ~GradeBook() {
        delete[] students;
    }

    void addStudent() {
        if (size == capacity)
            resize();
        int id;
        string name;
        float grade;
        cout << "ID: ";
        cin >> id;
        cout << "Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Grade: ";
        cin >> grade;
        students[size++] = Student(id, name, grade);
        sortStudents();
    }

    void displayAll() {
        for (int i = 0; i < size; i++)
            students[i].display();
    }

    void showStudent(int i) {
        if (i >= 0 && i < size)
            students[i].display();
    }

    void saveToFile(string filename) {
        ofstream file(filename);
        for (int i = 0; i < size; i++)
            file << students[i].id << " " << students[i].name << " " << students[i].grade << endl;
        cout << "Saved.\n";
    }

    void loadFromFile(string filename) {
        ifstream file(filename);
        size = 0;
        while (file) {
            int id;
            string name;
            float grade;
            file >> id >> name >> grade;
            if (file) {
                if (size == capacity)
                    resize();
                students[size++] = Student(id, name, grade);
            }
        }
        sortStudents();
        cout << "Loaded.\n";
    }

    int binarySearch(int id) {
        int l = 0, r = size - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (students[m].id == id)
                return m;
            else if (students[m].id < id)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};

// ===== Main Function =====
int main() {
    GradeBook gb;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Show All\n3. Search by ID\n4. Save\n5. Load\n0. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1)
            gb.addStudent();
        else if (choice == 2)
            gb.displayAll();
        else if (choice == 3) {
            int id;
            cout << "ID: ";
            cin >> id;
            int i = gb.binarySearch(id);
            if (i != -1)
                gb.showStudent(i);
            else
                cout << "Not found.\n";
        }
        else if (choice == 4)
            gb.saveToFile("students.txt");
        else if (choice == 5)
            gb.loadFromFile("students.txt");
    } while (choice != 0);

    return 0;
}
