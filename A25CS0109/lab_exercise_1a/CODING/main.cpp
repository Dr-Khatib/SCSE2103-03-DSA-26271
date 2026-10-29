/** 
 * @file main.cpp 
 * Client file to demonstrate BankAccount ADT 
 */ 
#include <iostream> 
#include "BankAccount.h" 
 
// TODO 8: Complete parameter type to receive BankAccount object by CONST REFERENCE 
void printAccountSummary(const BankAccount &account) { 
    std::cout << "\n[Summary via Const Reference Parameter]\n"; 
    account.display(); 
} 
 
int main() { 
    // TODO 9: Declare an array named 'accounts' storing 3 BankAccount objects 
    BankAccount accounts[3] = { 
        BankAccount("ACC-101", "Alice Smith", 500.0), 
        BankAccount("ACC-102", "Bob Jones", 1200.50), 
        BankAccount("ACC-103", "Charlie Brown", 250.75) 
    }; 
 
    std::cout << "=== INITIAL ACCOUNT STATES ===\n"; 
 
    // TODO 10: Complete loop calling display() for each object in the array 
    for (int i = 0; i < 3; ++i) { 
        accounts[i].display(); 
    } 
 
    std::cout << "\n=== PERFORMING TRANSACTIONS ===\n"; 
 
    // Deposit into the first account 
    accounts[0].deposit(150.0); 
 
    // Withdraw from second account 
    accounts[1].withdraw(300.0); 
 
    // TODO 11: Pass the first account to printAccountSummary 
    printAccountSummary(accounts[0]); 
 
    return 0; 
}