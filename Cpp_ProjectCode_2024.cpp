#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Account {
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(int accNum, string name) : accountNumber(accNum), accountHolderName(name), balance(0.0) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    string getAccountHolderName() const {
        return accountHolderName;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    void transfer(Account &receiver, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.deposit(amount);
            cout << "Transferred: $" << amount << " to account " << receiver.getAccountNumber() << endl;
        } else {
            cout << "Invalid transfer amount!" << endl;
        }
    }
};

class BankingSystem {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        int accNum = accounts.size() + 1; // Auto-increment account number
        string name;
        cout << "Enter account holder name: ";
        cin.ignore(); // Clear the newline character in the input buffer
        getline(cin, name);
        accounts.emplace_back(accNum, name);
        cout << "Account created successfully! Account Number: " << accNum << endl;
    }

    void deposit() {
        int accNum;
        double amount;
        cout << "Enter account number: ";
        cin >> accNum;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (accNum > 0 && accNum <= accounts.size()) {
            accounts[accNum - 1].deposit(amount);
        } else {
            cout << "Invalid account number!" << endl;
        }
    }

    void withdraw() {
        int accNum;
        double amount;
        cout << "Enter account number: ";
        cin >> accNum;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (accNum > 0 && accNum <= accounts.size()) {
            accounts[accNum - 1].withdraw(amount);
        } else {
            cout << "Invalid account number!" << endl;
        }
    }

    void balanceEnquiry() {
        int accNum;
        cout << "Enter account number: ";
        cin >> accNum;

        if (accNum > 0 && accNum <= accounts.size()) {
            cout << "Balance for account " << accNum << ": $" << accounts[accNum - 1].getBalance() << endl;
        } else {
            cout << "Invalid account number!" << endl;
        }
    }

    void transfer() {
        int senderAccNum, receiverAccNum;
        double amount ;
        cout << "Enter sender account number: ";
        cin >> senderAccNum;
        cout << "Enter receiver account number: ";
        cin >> receiverAccNum;
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (senderAccNum > 0 && senderAccNum <= accounts.size() && receiverAccNum > 0 && receiverAccNum <= accounts.size()) {
            accounts[senderAccNum - 1].transfer(accounts[receiverAccNum - 1], amount);
        } else {
            cout << "Invalid account numbers!" << endl;
        }
    }

    void menu() {
        int choice;
        do {
            cout << "\n--- Banking System Menu ---\n";
            cout << "1. Create Account\n";
            cout << "2. Deposit\n";
            cout << "3. Withdraw\n";
            cout << "4. Balance Enquiry\n";
            cout << "5. Transfer\n";
            cout << "6. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    createAccount();
                    break;
                case 2:
                    deposit();
                    break;
                case 3:
                    withdraw();
                    break;
                case 4:
                    balanceEnquiry();
                    break;
                case 5:
                    transfer();
                    break;
                case 6:
                    cout << "Exiting the Banking System. Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice! Please try again." << endl;
                    break;
            }
        } while (choice != 6);
    }
};

int main() {
    BankingSystem bankSystem;
    bankSystem.menu();
    return 0;
}
