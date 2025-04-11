#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    string accountNumber;
    double balance;

public:
    Account(string accNum, double bal) : accountNumber(accNum), balance(bal) {}

    friend class Manager;
    friend void transferFunds(Account& from, Account& to, double amount);
};

class Manager {
public:
    void displayAccountDetails(const Account& acc) {
        cout << "account Number: " << acc.accountNumber << endl;
        cout << "balance: " << acc.balance << endl;
    }

    void deposit(Account& acc, double amount) {
        acc.balance += amount;
    }

    void withdraw(Account& acc, double amount) {
        if (amount <= acc.balance) {
            acc.balance -= amount;
        } else {
            cout << "insufficient balance." << endl;
        }
    }
};

void transferFunds(Account& from, Account& to, double amount) {
    if (amount <= from.balance) {
        from.balance -= amount;
        to.balance += amount;
    } else {
        cout << "insufficient balance for transfer." << endl;
    }
}

int main() {
    Account acc1("12345", 1000.0);
    Account acc2("67890", 500.0);

    Manager manager;

    cout << "initial account details:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    manager.deposit(acc1, 200.0);
    manager.withdraw(acc2, 100.0);

    cout << "\nafter deposit and withdrawal:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    transferFunds(acc1, acc2, 300.0);

    cout << "\nafter transfer:" << endl;
    manager.displayAccountDetails(acc1);
    manager.displayAccountDetails(acc2);

    return 0;
}