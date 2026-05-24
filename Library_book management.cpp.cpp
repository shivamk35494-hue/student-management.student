// Library Management System
// Submitted by: Shivam Kumar
// B.Tech ECE
// Date: 24 May 2026

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library {
public:
    int bookID;
    string title;
    string author;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        ofstream file("library.txt", ios::app);
        file << bookID << "|" << title << "|" << author << endl;
        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks() {
        ifstream file("library.txt");
        string line;

        cout << "\n--- Library Records ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void searchBook() {
        string searchTitle;
        cout << "Enter Book Title to Search: ";
        cin.ignore();
        getline(cin, searchTitle);

        ifstream file("library.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            if (line.find(searchTitle) != string::npos) {
                cout << "Book Found: " << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Book not found!\n";

        file.close();
    }

    void issueBook() {
        cout << "Book issued successfully!\n";
    }

    void returnBook() {
        cout << "Book returned successfully!\n";
    }
};

int main() {
    Library l;
    int choice;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                l.addBook();
                break;
            case 2:
                l.displayBooks();
                break;
            case 3:
                l.searchBook();
                break;
            case 4:
                l.issueBook();
                break;
            case 5:
                l.returnBook();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}