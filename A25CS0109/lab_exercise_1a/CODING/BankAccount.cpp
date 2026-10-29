/** 
 * @file BankAccount.cpp 
 * Implementation of BankAccount ADT 
 */ 
#include "BankAccount.h" 
#include <iostream> 
 
// Default Constructor initialization 
BankAccount::BankAccount() 
    : accountNumber("0000"), accountHolder("N/A"), balance(0.0) { 
} 
 
// TODO 4: Complete the Parameterized Constructor implementation 
BankAccount::BankAccount(std::string accNum, std::string holder, double initialBalance) 
    : accountNumber(accNum), accountHolder(holder) { 
    if (initialBalance >= 0.0) { 
        /* Set balance member variable to initialBalance */ 
        balance = initialBalance; 
    } else { 
        /* Set balance to default 0.0 when negative balance provided */ 
        balance = 0.0; 
    } 
} 

// Destructor 
BankAccount::~BankAccount() { 
} 
 
void BankAccount::deposit(double amount) { 
    if (amount > 0) { 
        balance += amount; 
        std::cout << "Deposited $" << amount << " successfully.\n"; 
    } else { 
        std::cout << "Invalid deposit amount!\n"; 
    } 
} 
 
// TODO 5: Complete the withdraw member function header with scope resolution 
bool BankAccount::withdraw(double amount) { 
 
    // TODO 6: Complete condition checking if amount is positive AND balance is sufficient 
    if (amount > 0 && balance >= amount) { 
        balance -= amount; 
        std::cout << "Withdrew $" << amount << " successfully.\n"; 
        return true; 
    } else { 
        std::cout << "Withdrawal failed: Insufficient funds or invalid amount.\n"; 
        return false; 
    } 
} 
 
// TODO 7: Complete getBalance scope resolution and return statement 
double BankAccount::getBalance() const { 
    return balance; 
} 
 
void BankAccount::display() const { 
    std::cout << "----------------------------\n"; 
    std::cout << "Account Number : " << accountNumber << "\n"; 
    std::cout << "Account Holder : " << accountHolder << "\n"; 
    std::cout << "Current Balance: $" << balance << "\n"; 
    std::cout << "----------------------------\n"; 
} 