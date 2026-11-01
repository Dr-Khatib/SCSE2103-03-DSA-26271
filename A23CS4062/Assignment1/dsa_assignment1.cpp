/*
 * Course: Data Structures & Algorithms (C++)
 * Lab Exercise: Comprehensive DSA Debug & Code Completion
 * Grounded in Chapters 1 - 4
 *
 * Completed: Tasks 1-10 (5 debugging tasks, 5 completion tasks)
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

    // TASK 2 [COMPLETE]: Update GPA with validation.
    // If newGpa is in [0.0, 4.0], update gpa and return true.
    // Otherwise print an error message and return false.
    bool setGPA(float newGpa) {
        if (newGpa >= 0.0f && newGpa <= 4.0f) {
            gpa = newGpa;
            return true;
        }
        cout << "Error: GPA " << newGpa << " is out of range (0.0 - 4.0). GPA not updated." << endl;
        return false;
    }
};

// ============================================================================
// TASK 1 [DEBUG]: POINTER TO OBJECT FUNCTION
// ============================================================================
// BUG: '.' was used on a pointer. Pointers to objects must use '->'.
void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        ptr->printStudent();   // FIXED (TASK 1)
    }
}


// ============================================================================
// TASK 3 [DEBUG] & TASK 4 [COMPLETE]: ARRAY OF OBJECTS OPERATIONS
// ============================================================================

// TASK 3 [DEBUG]: Display all students in an array.
// BUG: loop ran to i == size, which is one past the last valid index.
void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    for (int i = 0; i < size; i++) {   // FIXED (TASK 3): valid indices are 0 .. size-1
        list[i].printStudent();
    }
}

// TASK 4 [COMPLETE]: Average GPA of a Student array.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    float totalGpa = 0.0f;

    for (int i = 0; i < size; i++) {
        totalGpa += list[i].getGPA();
    }
    return totalGpa / size;
}


// ============================================================================
// CHAPTER 2B: ADVANCED BINARY FILE OPERATIONS
// ============================================================================

// TASK 5 [DEBUG]: Save an array of objects to a binary file.
// BUG: file was opened without ios::binary, and "<<" was used,
//      which has no meaning for a Student object. Raw bytes must be written with write().
void saveToBinaryFile(const char* filename, const Student list[], int size) {
    fstream outFile(filename, ios::out | ios::binary);   // FIXED: binary flag added
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        // FIXED: write the raw bytes of each record
        outFile.write(reinterpret_cast<const char*>(&list[i]), sizeof(Student));
    }
    outFile.close();
    cout << "Successfully saved records to binary file: " << filename << endl;
}

// TASK 6 [COMPLETE]: Random-access read of a single record.
// Record offset = recordIndex * sizeof(Student).
bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    fstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }

    streamoff offset = static_cast<streamoff>(recordIndex) * static_cast<streamoff>(sizeof(Student));
    inFile.seekg(offset, ios::beg);
    inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));

    bool success = static_cast<bool>(inFile);   // true only if the full record was read
    inFile.close();
    return success;
}


// ============================================================================
// CHAPTER 3: RECURSION
// ============================================================================

// TASK 7 [DEBUG]: Factorial of n.
// BUG: no base case, and the recursive call passed n instead of n - 1,
//      so the recursion never ended.
int recursiveFactorial(int n) {
    if (n <= 1) return 1;                    // FIXED: base case
    return n * recursiveFactorial(n - 1);    // FIXED: recursive step shrinks n
}

// TASK 8 [COMPLETE]: Recursive linear search for a Student ID.
// Returns the index of targetID, or -1 if not found.
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    // Base Case 1: reached the end of the array without a match
    if (currentIndex >= size) return -1;

    // Base Case 2: found the target
    if (list[currentIndex].getID() == targetID) return currentIndex;

    // General Case: search the next index
    return recursiveSearchID(list, size, targetID, currentIndex + 1);
}


// ============================================================================
// CHAPTER 4: ALGORITHM EFFICIENCY & STEP COUNTING
// ============================================================================

// TASK 9 [DEBUG]: Nested loop operation counter.
// NOTE: the original version did terminate (j++ was in the body), so this is a
// style fix: the increment was moved into the for-loop header so that the loop
// variable's update is visible in one place.
void analyzeAlgorithmComplexity(int n) {
    int totalSteps = 0;
    cout << "\n--- Algorithm Efficiency Analysis (N = " << n << ") ---" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {   // FIXED: increment in the loop header
            totalSteps++;
        }
    }
    cout << "Total Basic Operations Executed: " << totalSteps << " steps." << endl;
    cout << "Theoretical Complexity: O(N^2)" << endl;
}

// TASK 10 [COMPLETE]: Halving loop step count analysis.
// i starts at n and is halved each iteration until it reaches 0.
void analyzeLogarithmicEfficiency(int n) {
    int stepCount = 0;

    int i = n;
    while (i > 0) {
        stepCount++;
        i /= 2;
    }

    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
    // Complexity: O(log N)
    // For n >= 1 the step count is floor(log2 N) + 1 (e.g. N = 16 gives 5 steps).
    // Because the problem size is halved on every step, the number of steps grows
    // logarithmically with N, so the algorithm runs in O(log N) time.
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
    displayUsingPointer(&s1);                        // Task 1

    if (s1.setGPA(3.80f)) cout << "Valid GPA accepted." << endl;      // Task 2
    if (!s1.setGPA(4.50f)) cout << "Invalid GPA correctly rejected." << endl;
    s1.printStudent();

    // Test Task 3 & 4
    printAllStudents(roster, ROSTER_SIZE);           // Task 3
    float avgGpa = calculateAverageGPA(roster, ROSTER_SIZE);   // Task 4
    cout << "Calculated Average GPA: " << avgGpa << endl;

    // Test Task 5 & 6
    const char* binaryFileName = "students.dat";
    saveToBinaryFile(binaryFileName, roster, ROSTER_SIZE);     // Task 5

    Student retrievedStudent;
    if (readRecordAt(binaryFileName, 1, retrievedStudent)) {   // Task 6
        cout << "Successfully retrieved record at index 1:" << endl;
        retrievedStudent.printStudent();
    }

    // Test Task 7 & 8
    int fact = recursiveFactorial(4);                          // Task 7
    cout << "Factorial of 4 = " << fact << endl;
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102);   // Task 8
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    // Test Task 9 & 10
    analyzeAlgorithmComplexity(4);                   // Task 9
    analyzeLogarithmicEfficiency(16);                // Task 10

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    return 0;
}
