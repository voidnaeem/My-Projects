#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Transaction structure to store history
struct Transaction {
    string type;
    float amount;
    float balance;
};

// ATM Class
class ATM {
    private:
        string ownerName;
        string pin;
        float balance;
        vector<Transaction> history;

    public:
        // Constructor
        ATM(string name, string userPin, float initialBalance) {
            ownerName      = name;
            pin            = userPin;
            balance        = initialBalance;
        }

        // Check PIN
        bool checkPin(string enteredPin) {
            return enteredPin == pin;
        }

        // Check Balance
        void checkBalance() {
            cout << "\n============================" << endl;
            cout << "  Account Holder : " << ownerName << endl;
            cout << "  Balance        : Rs " << balance << endl;
            cout << "============================" << endl;
        }

        // Deposit Money
        void deposit(float amount) {
            if (amount <= 0) {
                cout << "\n[Error] Amount must be greater than 0." << endl;
                return;
            }
            balance += amount;
            Transaction t;
            t.type    = "Deposit";
            t.amount  = amount;
            t.balance = balance;
            history.push_back(t);
            cout << "\n[Success] Rs " << amount << " deposited!" << endl;
            cout << "New Balance: Rs " << balance << endl;
        }

        // Withdraw Money
        void withdraw(float amount) {
            if (amount <= 0) {
                cout << "\n[Error] Amount must be greater than 0." << endl;
                return;
            }
            if (amount > balance) {
                cout << "\n[Error] Insufficient balance!" << endl;
                return;
            }
            balance -= amount;
            Transaction t;
            t.type    = "Withdraw";
            t.amount  = amount;
            t.balance = balance;
            history.push_back(t);
            cout << "\n[Success] Rs " << amount << " withdrawn!" << endl;
            cout << "New Balance: Rs " << balance << endl;
        }

        // Show Transaction History
        void showHistory() {
            if (history.empty()) {
                cout << "\nNo transactions yet." << endl;
                return;
            }
            cout << "\n============================" << endl;
            cout << "    Transaction History      " << endl;
            cout << "============================" << endl;
            for (int i = 0; i < history.size(); i++) {
                cout << i + 1 << ". "
                     << history[i].type
                     << " | Rs " << history[i].amount
                     << " | Balance: Rs " << history[i].balance
                     << endl;
            }
            cout << "============================" << endl;
        }

        // Change PIN
        void changePin(string oldPin, string newPin) {
            if (oldPin != pin) {
                cout << "\n[Error] Wrong old PIN!" << endl;
                return;
            }
            pin = newPin;
            cout << "\n[Success] PIN changed successfully!" << endl;
        }
};

// Main Menu
int main() {
    // Create ATM object
    ATM myATM("Ali Khan", "1234", 5000);

    string enteredPin;
    int attempts = 0;

    cout << "============================" << endl;
    cout << "      Welcome to ATM        " << endl;
    cout << "============================" << endl;

    // PIN verification (max 3 attempts)
    while (attempts < 3) {
        cout << "\nEnter PIN: ";
        cin >> enteredPin;

        if (myATM.checkPin(enteredPin)) {
            cout << "\n[Success] PIN correct! Welcome " << endl;
            break;
        } else {
            attempts++;
            cout << "[Error] Wrong PIN! Attempts left: " << 3 - attempts << endl;
        }

        if (attempts == 3) {
            cout << "\n[Blocked] Too many wrong attempts. Card blocked!" << endl;
            return 0;
        }
    }

    // Main Menu Loop
    int choice;
    do {
        cout << "\n============================" << endl;
        cout << "         ATM MENU           " << endl;
        cout << "============================" << endl;
        cout << "1. Check Balance"             << endl;
        cout << "2. Deposit Money"             << endl;
        cout << "3. Withdraw Money"            << endl;
        cout << "4. Transaction History"       << endl;
        cout << "5. Change PIN"                << endl;
        cout << "6. Exit"                      << endl;
        cout << "============================" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            myATM.checkBalance();

        } else if (choice == 2) {
            float amount;
            cout << "Enter deposit amount: Rs ";
            cin >> amount;
            myATM.deposit(amount);

        } else if (choice == 3) {
            float amount;
            cout << "Enter withdraw amount: Rs ";
            cin >> amount;
            myATM.withdraw(amount);

        } else if (choice == 4) {
            myATM.showHistory();

        } else if (choice == 5) {
            string oldPin, newPin;
            cout << "Enter old PIN: ";
            cin >> oldPin;
            cout << "Enter new PIN: ";
            cin >> newPin;
            myATM.changePin(oldPin, newPin);

        } else if (choice == 6) {
            cout << "\nThank you for using ATM. Goodbye!" << endl;

        } else {
            cout << "\n[Error] Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
