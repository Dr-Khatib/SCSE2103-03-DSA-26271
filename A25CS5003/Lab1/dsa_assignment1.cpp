/*
 * Course: Data Structures & Algorithms (C++)
 * Lab Exercise: Comprehensive DSA Debug & Code Completion
 * Grounded in Chapters 1 - 4
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// ============================================================================
// CHAPTER 1 & 2A: ABSTRACT DATA TYPES, CLASSES & POINTERS TO OBJECTS
// ============================================================================

class Student {
private:
    char name[30];
    int studentID;
    float gpa;

public:
    // Default Constructor
    Student() {
        strcpy(name, "Undefined");
        studentID = 0;
        gpa = 0.0f;
    }

    // Parameterized Constructor
    Student(const char* n, int id, float g) {
        strncpy(name, n, 29);
        name[29] = '\0';
        studentID = id;
        gpa = g;
    }

    // Accessors (Getters)
    int getID() const { return studentID; }
    float getGPA() const { return gpa; }
    const char* getName() const { return name; }

    // Display Member Function
    void printStudent() const {
        cout << "ID: " << studentID << " | Name: " << name << " | GPA: " << gpa << endl;
    }

    // TASK 2 [COMPLETE]: Implement a member function to update GPA with validation.
    bool setGPA(float newGpa) {
        if (newGpa >= 0.0f && newGpa <= 4.0f) {
            gpa = newGpa;
            return true;
        } else {
            cout << "Error: Invalid GPA value!" << endl;
            return false;
        }
    }
};

// ============================================================================
// TASK 1 [DEBUG]: POINTER TO OBJECT FUNCTION
// ============================================================================
void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        // --- BUG FIXED (TASK 1) ---
        ptr->printStudent(); 
    }
}


// ============================================================================
// TASK 3 [DEBUG] & TASK 4 [COMPLETE]: ARRAY OF OBJECTS OPERATIONS
// ============================================================================

// TASK 3 [DEBUG]: Function intended to display all students in an array.
void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    // --- BUG FIXED (TASK 3) ---
    for (int i = 0; i < size; i++) { 
        list[i].printStudent();
    }
}

// TASK 4 [COMPLETE]: Calculate Average GPA of Student Array.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    float totalGpa = 0.0f;

    // TODO (TASK 4): Write loop here to sum GPAs and calculate average.
    for (int i = 0; i < size; i++) {
        totalGpa += list[i].getGPA();
    }

    return totalGpa / size;
}


// ============================================================================
// CHAPTER 2B: ADVANCED BINARY FILE OPERATIONS
// ============================================================================

// TASK 5 [DEBUG]: Save Array of Objects to Binary File.
void saveToBinaryFile(const char* filename, const Student list[], int size) {
    // --- BUG FIXED (TASK 5) ---
    fstream outFile(filename, ios::out | ios::binary); 
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
         outFile.write(reinterpret_cast<const char*>(&list[i]), sizeof(Student)); 
    }
    outFile.close();
    cout << "Successfully saved records to binary file: " << filename << endl;
}

// TASK 6 [COMPLETE]: Random-Access Reading of a Single Record.
bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    fstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }

    // TODO (TASK 6): Complete the seekg() positioning and read() execution.
    streamoff offset = static_cast<streamoff>(recordIndex) * sizeof(Student);
    inFile.seekg(offset, ios::beg);
    if (inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student))) {
        inFile.close();
        return true;
    }

    inFile.close();
    return false;
}


// ============================================================================
// CHAPTER 3: RECURSION
// ============================================================================

// TASK 7 [DEBUG]: Recursive Function to Compute Factorial of Total Students.
int recursiveFactorial(int n) {
    // --- BUG FIXED (TASK 7) ---
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1); 
}

// TASK 8 [COMPLETE]: Recursive Linear Search for Student ID.
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    // TODO (TASK 8): Write base cases and recursive step here.
    if (currentIndex >= size) return -1;
    if (list[currentIndex].getID() == targetID) return currentIndex;
    return recursiveSearchID(list, size, targetID, currentIndex + 1);
}


// ============================================================================
// CHAPTER 4: ALGORITHM EFFICIENCY & STEP COUNTING
// ============================================================================

// TASK 9 [DEBUG]: Nested Loop Operation Counter.
void analyzeAlgorithmComplexity(int n) {
    int totalSteps = 0;
    cout << "\n--- Algorithm Efficiency Analysis (N = " << n << ") ---" << endl;

    // --- BUG FIXED (TASK 9) ---
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            totalSteps++;
        }
    }
    cout << "Total Basic Operations Executed: " << totalSteps << " steps." << endl;
    cout << "Theoretical Complexity: O(N^2)" << endl;
}

// TASK 10 [COMPLETE]: Halving Loop Step Count Analysis.
void analyzeLogarithmicEfficiency(int n) {
    int stepCount = 0;
    int temp = n;

    // TODO (TASK 10): Implement while loop or for loop where i halves each step
    while (temp > 0) {
        stepCount++;
        temp /= 2;
    }

    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
    // TODO (TASK 10 Comment): State the Big O complexity class of this algorithm below:
    // Complexity: O(log N)
}


// ============================================================================
// MAIN FUNCTION (TESTBENCH)
// ============================================================================

int main() {
    cout << "=======================================================" << endl;
    cout << "  DSA Comprehensive Lab Exercise (Chapters 1 - 4)    " << endl;
    cout << "=======================================================" << endl;

    // 1. Initialize Array of Objects
    const int ROSTER_SIZE = 3;
    Student roster[ROSTER_SIZE] = {
        Student("Ahmad", 101, 3.75f),
        Student("Siti",  102, 3.90f),
        Student("Chong", 103, 3.50f)
    };

    // Test Task 1 & 2
    cout << "\n--- Testing ADT & Pointers ---" << endl;
    Student s1("Nurul", 104, 3.20f);
    displayUsingPointer(&s1); // Task 1

    // Test Task 3 & 4
    printAllStudents(roster, ROSTER_SIZE); // Task 3
    float avgGpa = calculateAverageGPA(roster, ROSTER_SIZE); // Task 4
    cout << "Calculated Average GPA: " << avgGpa << endl;

    // Test Task 5 & 6
    const char* binaryFileName = "students.dat";
    saveToBinaryFile(binaryFileName, roster, ROSTER_SIZE); // Task 5

    Student retrievedStudent;
    if (readRecordAt(binaryFileName, 1, retrievedStudent)) { // Task 6
        cout << "Successfully retrieved record at index 1:" << endl;
        retrievedStudent.printStudent();
    }

    // Test Task 7 & 8
    int fact = recursiveFactorial(4); // Task 7
    cout << "Factorial of 4: " << fact << endl;
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102); // Task 8
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    // Test Task 9 & 10
    analyzeAlgorithmComplexity(4); // Task 9
    analyzeLogarithmicEfficiency(16); // Task 10

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    return 0;
}