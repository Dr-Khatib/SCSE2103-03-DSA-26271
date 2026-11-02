/*
 * Course: Data Structures & Algorithms (C++)
 * Lab Exercise: Comprehensive DSA Debug & Code Completion
 * Grounded in Chapters 1 - 4
 *
 * INSTRUCTIONS FOR STUDENTS:
 * This single C++ source file contains 10 tasks covering:
 *  - Chapter 1: Problem Solving & Basic Data Structures
 *  - Chapter 2A: Abstract Data Types & Object Pointers
 *  - Chapter 2B: Binary File Operations (fstream, seekg, reinterpret_cast)
 *  - Chapter 3: Recursion & Base Case Design
 *  - Chapter 4: Algorithm Efficiency & Step Counting (Big O)
 *
 * TASK TYPES:
 *  - 5 DEBUGGING TASKS (Tasks 1, 3, 5, 7, 9): Locate the bug, fix the code, and uncomment/correct it.
 *  - 5 COMPLETION TASKS (Tasks 2, 4, 6, 8, 10): Implement the missing code logic specified in the TODO comments.
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
    // Requirement: If newGpa is between 0.0 and 4.0 (inclusive), update gpa and return true.
    // Otherwise, print an error message and return false.
    bool setGPA(float newGpa) {
        // FIXED (TASK 2): validate the range first, then assign.
        if (newGpa >= 0.0f && newGpa <= 4.0f) {
            gpa = newGpa;
            return true;
        }
        cout << "Error: GPA must be between 0.0 and 4.0. Update rejected." << endl;
        return false;
    }
};

// ============================================================================
// TASK 1 [DEBUG]: POINTER TO OBJECT FUNCTION
// ============================================================================
// Goal: Print student info using a pointer to an object.
// BUG DESCRIPTION: The function below uses dot operator '.' on an object pointer.
void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        // FIXED (TASK 1): an object pointer must use the arrow operator '->', not '.'.
        ptr->printStudent();
    }
}


// ============================================================================
// TASK 3 [DEBUG] & TASK 4 [COMPLETE]: ARRAY OF OBJECTS OPERATIONS
// ============================================================================

// TASK 3 [DEBUG]: Function intended to display all students in an array.
// BUG DESCRIPTION: Loop index off-by-one bug causes array out-of-bounds access.
void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    // FIXED (TASK 3): valid indices are 0 .. size-1, so the condition must be i < size.
    for (int i = 0; i < size; i++) {
        list[i].printStudent();
    }
}

// TASK 4 [COMPLETE]: Calculate Average GPA of Student Array.
// Requirement: Iterate through list[] up to 'size' elements and return the average GPA.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    float totalGpa = 0.0f;

    // FIXED (TASK 4): accumulate every GPA, then divide by the number of students.
    for (int i = 0; i < size; i++) {
        totalGpa += list[i].getGPA();
    }

    return totalGpa / size;
}


// ============================================================================
// CHAPTER 2B: ADVANCED BINARY FILE OPERATIONS
// ============================================================================

// TASK 5 [DEBUG]: Save Array of Objects to Binary File.
// BUG DESCRIPTION: Missing binary flag and wrong stream output operator used instead of write().
void saveToBinaryFile(const char* filename, const Student list[], int size) {
    // FIXED (TASK 5): add ios::binary so raw bytes are written without translation.
    fstream outFile(filename, ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        // FIXED (TASK 5): use write() with reinterpret_cast to store the raw object bytes.
        outFile.write(reinterpret_cast<const char*>(&list[i]), sizeof(Student));
    }
    outFile.close();
    cout << "Successfully saved records to binary file: " << filename << endl;
}

// TASK 6 [COMPLETE]: Random-Access Reading of a Single Record.
// Requirement: Open 'filename' in binary input mode (ios::in | ios::binary).
// Use seekg() to jump directly to recordIndex (offset = recordIndex * sizeof(Student)).
// Read the record into 'outStudent' using read() and reinterpret_cast<char*>.
bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    fstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }

    // FIXED (TASK 6): compute the byte offset, seek to it, then read one full record.
    streamoff offset = recordIndex * sizeof(Student);
    inFile.seekg(offset, ios::beg);
    inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));

    bool ok = static_cast<bool>(inFile);
    inFile.close();
    return ok;
}


// ============================================================================
// CHAPTER 3: RECURSION
// ============================================================================

// TASK 7 [DEBUG]: Recursive Function to Compute Factorial of Total Students.
// BUG DESCRIPTION: Infinite recursion due to missing base case and non-decreasing recursive step.
int recursiveFactorial(int n) {
    // FIXED (TASK 7): base case stops the recursion, and each call moves toward it (n - 1).
    if (n <= 1) {
        return 1;
    }
    return n * recursiveFactorial(n - 1);
}

// TASK 8 [COMPLETE]: Recursive Linear Search for Student ID.
// Requirement: Recursively search 'list' from index 0 up to 'size - 1' for 'targetID'.
// Base Case 1: If current index reaches 'size', return -1 (Not Found).
// Base Case 2: If list[index].getID() == targetID, return index (Found).
// General Case: Recursively search next index (index + 1).
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    // FIXED (TASK 8): base case 1 - reached the end without a match.
    if (currentIndex >= size) {
        return -1;
    }
    // FIXED (TASK 8): base case 2 - target found at the current index.
    if (list[currentIndex].getID() == targetID) {
        return currentIndex;
    }
    // FIXED (TASK 8): general case - keep searching the next index.
    return recursiveSearchID(list, size, targetID, currentIndex + 1);
}


// ============================================================================
// CHAPTER 4: ALGORITHM EFFICIENCY & STEP COUNTING
// ============================================================================

// TASK 9 [DEBUG]: Nested Loop Operation Counter.
// BUG DESCRIPTION: Loop termination variable error causing infinite loop during step counting.
void analyzeAlgorithmComplexity(int n) {
    int totalSteps = 0;
    cout << "\n--- Algorithm Efficiency Analysis (N = " << n << ") ---" << endl;

    // FIXED (TASK 9): the inner loop's update (j++) belongs in the for-header so the
    // loop is guaranteed to terminate; total steps = n * n = N^2.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            totalSteps++;
        }
    }
    cout << "Total Basic Operations Executed: " << totalSteps << " steps." << endl;
    cout << "Theoretical Complexity: O(N^2)" << endl;
}

// TASK 10 [COMPLETE]: Halving Loop Step Count Analysis.
// Requirement: Complete the logarithmic loop where 'i' starts at 'n' and halves (i = i / 2) each iteration.
// Count total steps executed and print both step count and Big O complexity in comments.
void analyzeLogarithmicEfficiency(int n) {
    int stepCount = 0;

    // FIXED (TASK 10): i is halved every iteration until it reaches 0.
    for (int i = n; i > 0; i /= 2) {
        stepCount++;
    }

    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
    // FIXED (TASK 10 Comment): the number of halvings is log2(N), so the complexity class is:
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

    // Task 2 verification (valid + invalid update). Calls are made before printing so
    // the side effect and the displayed value are unambiguous.
    bool validUpdate = s1.setGPA(4.0f);
    cout << "setGPA(4.0) returns: " << validUpdate << " | new GPA: " << s1.getGPA() << endl;
    bool invalidUpdate = s1.setGPA(5.0f);
    cout << "setGPA(5.0) returns: " << invalidUpdate << " | GPA unchanged: " << s1.getGPA() << endl;

    // Test Task 3 & 4
    printAllStudents(roster, ROSTER_SIZE); // Task 3 (uncommented after fix)
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
    int fact = recursiveFactorial(4); // Task 7 (uncommented after fix)
    cout << "Recursive Factorial of 4: " << fact << endl;
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102); // Task 8
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    // Test Task 9 & 10
    analyzeAlgorithmComplexity(4); // Task 9
    analyzeLogarithmicEfficiency(16); // Task 10

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    return 0;
}
