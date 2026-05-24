// Bank Management Application
// Submitted by: Shivam Kumar
// B.Tech ECE
// Date: 24 May 2026

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accNo;
    string name;
    float balance;

    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;

        ofstream file("bank.txt", ios::app);
        file << accNo << "|" << name << "|" << balance << endl;
        file.close();

        cout << "\nAccount Created Successfully!\n";
    }

    void displayAccounts() {
        ifstream file("bank.txt");
        string line;

        cout << "\n--- Customer Records ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void checkBalance() {
        int searchAcc;
        cout << "Enter Account Number: ";
        cin >> searchAcc;

        ifstream file("bank.txt");
        string line;
        bool found = false;

        while (getline(file, line)) {
            if (stoi(line.substr(0, line.find("|"))) == searchAcc) {
                cout << "Account Found: " << line << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Account not found!\n";

        file.close();
    }
};

int main() {
    BankAccount b;
    int choice;

    do {
        cout << "\n===== Bank Management Application =====\n";
        cout << "1. Create Account\n";
        cout << "2. Display Accounts\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                b.createAccount();
                break;
            case 2:
                b.displayAccounts();
                break;
            case 3:
                b.checkBalance();
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