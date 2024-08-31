#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Structure to store account details
struct Account {
    string password;
    double balance;
};

// Unordered map to store user accounts with id as the key and Account struct as the value
unordered_map<string, Account> accounts;

// Function to create a new account
void createAccount() {
    string user_id, password;
    cout << "Please enter your user id: ";
    cin >> user_id;
    if (accounts.find(user_id) != accounts.end()) {
        cout << "User ID already exists. Please try again." << endl;
        return;
    }
    cout << "Please enter your password: ";
    cin >> password;
    accounts[user_id] = {password, 0.0};  // Initial balance is 0
    cout << "Thank You! Your account has been created!" << endl;
}

// Function to login to an account
string login() {
    string user_id, password;
    cout << "Please enter your user id: ";
    cin >> user_id;
    cout << "Please enter your password: ";
    cin >> password;

    if (accounts.find(user_id) != accounts.end() && accounts[user_id].password == password) {
        cout << "Access Granted!" << endl;
        return user_id;
    } else {
        cout << "*** LOGIN FAILED! ***" << endl;
        return "";
    }
}

// Function to deposit money into the account
void depositMoney(const string& user_id) {
    double amount;
    cout << "Amount of deposit: $";
    cin >> amount;
    accounts[user_id].balance += amount;
    cout << "$" << amount << " has been deposited to your account." << endl;
}

// Function to withdraw money from the account
void withdrawMoney(const string& user_id) {
    double amount;
    cout <<
