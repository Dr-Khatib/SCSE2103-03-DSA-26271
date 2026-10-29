/**
 * @file BankAccount.h 
 * Class specification for BankAccount ADT 
 */ 
#ifndef BANKACCOUNT_H 
#define BANKACCOUNT_H 
 
#include <iostream> 
#include <string> 
 
class BankAccount { 
/* TODO 1: Add access specifier for private data members */ 
private:
    std::string accountNumber; 
    std::string accountHolder; 
    double balance; 
 
/* TODO 2: Add access specifier for public member functions */ 
public: 
    // Default Constructor 
    BankAccount(); 
 
    // Parameterized Constructor 
    BankAccount(std::string accNum, std::string holder, double initialBalance); 
 
    // Destructor 
    ~BankAccount(); 
 
    // Mutator functions 
    void deposit(double amount); 
    bool withdraw(double amount); 
 
    // TODO 3: Declare getBalance() and display() as CONST member functions 
    double getBalance() const; 
    void display() const; 
}; 
 
#endif