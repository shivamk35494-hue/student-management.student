// Student Management System
// Submitted by: Shivam Kumar
// B.Tech ECE
// Date: 22 May 2026

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    void addStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;

        ofstream file("students.txt", ios::app);
        file << rollNo << "|" << name << "|" << marks << endl;
        file.close();

        cout << "\nStudent Added Successfully!\n";
    }

    void displayStudents() {
        ifstream file("students.txt");
        string line;

        cout << "\n--- Student Records ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void searchStudent() {
        int searchRoll;
        cout << "Enter Roll Number to Search: ";
        cin >> searchRoll;

        ifstream file("students.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            if (stoi(line.substr(0, line.find("|"))) == searchRoll) {
                cout << "Record Found: " << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Student not found!\n";

        file.close();
    }
};

int main() {
    Student s;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.addStudent();
                break;
            case 2:
                s.displayStudents();
                break;
            case 3:
                s.searchStudent();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}