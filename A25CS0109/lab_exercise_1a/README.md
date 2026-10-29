## Exercise 1A

### Lab Exercise: Bank Account ADT Implementation (Complete Answers)

<img width="350" alt="logo-FC-website-header" src="https://github.com/user-attachments/assets/d7ac3e9e-8322-47db-bf9a-658c928347c3" />

***Student Details:***
| Information    | Student Details |
| -------- | ------- |
| **Student Name**  | `MUHAMMAD NAWFAL BIN MOHD SHAIFUDDIN`    |
| **Matric No.** | `A25CS0109`     |
| **Course**    | `SCSE2103: DATA STRUCTURE AND ALGORITHM`    |
| **Section**    | `SECTION 03`    |
| **Lecturer Name**    | `DR. MUHAMMAD KHATIBSYARBINI`    |
| **Final Submission Date**    | `FRIDAY, 23 OCTOBER 2026, 12:00 AM`    |

---

### Instructions   
Complete the implementation of the BankAccount Abstract Data Type (ADT) and client application below. Fill in every missing code section marked with `/* TODO 1 */` through `/* TODO 11 */`.   

---

### Part 1: Header File (`BankAccount.h`)   
Fill in access specifiers and constant function qualifiers for the class definition.   

```
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
```

---

### Part 2: Implementation File (`BankAccount.cpp`)  
Complete constructor initializations, scope resolutions, and logic implementations.   

```
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
```

---

### Part 3: Client Application (`main.cpp`) 
Complete function signature for pass-by-const-reference and array operations.   

```
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
```

---

### Output   

```
=== INITIAL ACCOUNT STATES ===
----------------------------
Account Number : ACC-101
Account Holder : Alice Smith
Current Balance: $500
----------------------------
----------------------------
Account Number : ACC-102
Account Holder : Bob Jones
Current Balance: $1200.5
----------------------------
----------------------------
Account Number : ACC-103
Account Holder : Charlie Brown
Current Balance: $250.75
----------------------------

=== PERFORMING TRANSACTIONS ===
Deposited $150 successfully.
Withdrew $300 successfully.

[Summary via Const Reference Parameter]
----------------------------
Account Number : ACC-101
Account Holder : Alice Smith
Current Balance: $650
----------------------------
```
