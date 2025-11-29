#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
//
bool verifyPin(int correctPin){
/*
Prompts the user to enter their PIN. 
Allows a maximum of three attempts. 
Returns true if the PIN is correct, otherwise returns false.
*/
int attempts = 0;
    int enteredPin;

    while (attempts < 3) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (enteredPin == correctPin) {
            cout << "Welcome to your account!" << endl;
            return true;
        } else {
            attempts++;
            cout << "Incorrect PIN. ";
            if (attempts < 3) {
                cout << "You have " << 3 - attempts << " attempt(s) left." << endl;
            }
        }
    }

    cout << "Account Locked. Please contact your bank." << endl;
    return false;
}
//=======================================
//prints the ATM menu
void displayMenu(){
cout<<"======== ATM MENU ========"<<endl;
cout<<"1. View Balance  \n2. Deposit Cash \n3. Withdraw Cash \n4. Reset PIN \n5. Exit"<<endl;
cout << "Enter your choice: ";
}
//=======================================
//displays and returns the current balance.
double viewBalance(double balance){
    cout << "Your current balance is: ₦" << balance << endl;
    return balance;
}
//=======================================
//prompts the user to enter a deposit
double depositMoney(double balance){
    double deposit;
    cout << "Enter amount to deposit: ₦";
    cin >> deposit;

    if (deposit <= 0) {
        cout << "Invalid deposit amount!" << endl;
        return balance;
    }

    balance += deposit;
    cout << "Deposit successful! New balance: ₦" << balance << endl;
    return balance;
}
//=======================================
//double depositMoney(double balance)
double withdrawMoney(double balance, double dailyLimit){
    /*
Amount must not exceed the account balance. 
Amount must not exceed the daily withdrawal limit.
    */
double amount;
    cout << "Enter amount to withdraw: ₦";
    cin >> amount;

    if (amount <= 0) {
        cout << "Invalid withdrawal amount!" << endl;
    } else if (amount > balance) {
        cout << "Insufficient funds!" << endl;
    } else if (amount > dailyLimit) {
        cout << "Amount exceeds daily withdrawal limit of ₦" << dailyLimit << endl;
    } else {
        balance -= amount;
        cout << "Withdrawal successful! New balance: ₦" << balance << endl;
    }

    return balance;
}
//=======================================
//allows the user to enter their old PIN and set a new PIN
int resetPin(int currentPin){
int oldPin, newPin;
    cout << "Enter your current PIN: ";
    cin >> oldPin;

    if (oldPin != currentPin) {
        cout << "Incorrect current PIN. PIN reset failed." << endl;
        return currentPin;
    }

    cout << "Enter new PIN: ";
    cin >> newPin;
    cout << "PIN successfully changed!" << endl;
    return newPin;
}

int main() {
    double account_balance = 50000;
    double daily_withdrawal_limit = 20000;
    int user_PIN = 4321;

    // Verify PIN first
    if (!verifyPin(user_PIN)) {
        return 0; // Exit if PIN verification fails
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                account_balance = viewBalance(account_balance);
                break;
            case 2:
                account_balance = depositMoney(account_balance);
                break;
            case 3:
                account_balance = withdrawMoney(account_balance, daily_withdrawal_limit);
                break;
            case 4:
                user_PIN = resetPin(user_PIN);
                break;
            case 5:
                cout << "Thank you for using our ATM." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}