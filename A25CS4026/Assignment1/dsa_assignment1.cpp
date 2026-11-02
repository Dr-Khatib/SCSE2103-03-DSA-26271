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
        if (newGpa >= 0.0f && newGpa <=4.0f){
        	gpa = newGpa;
        	return true;
		}else{
			cout << "Error: GPA must be between 0.0 and 4.0."<<endl;
		}
        return false;
    }
};

// ============================================================================
// TASK 1 [DEBUG]: POINTER TO OBJECT FUNCTION
// ============================================================================
// Goal: Print student info using a pointer to an object.
// BUG DESCRIPTION: The function below uses dot operator '.' on an object pointer.
void displayUsingPointer(const Student* ptr) {
    if (ptr != NULL) {
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
    for (int i = 0; i < size; i++) { 
        list[i].printStudent();
    }
}

// TASK 4 [COMPLETE]: Calculate Average GPA of Student Array.
// Requirement: Iterate through list[] up to 'size' elements and return the average GPA.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    float totalGpa = 0.0f;

    for (int i=0; i<size; i++){
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
    fstream outFile(filename, ios::out | ios::binary); 
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        
         outFile.write(reinterpret_cast<const char*>(&list[i]), sizeof(Student)); 
        
    }
    outFile.close();
    if (!outFile) {
        cout << "Error saving records!" << endl;
        return;
    }
    cout << "Successfully saved records to binary file: " << filename << endl;
}

// TASK 6 [COMPLETE]: Random-Access Reading of a Single Record.
// Requirement: Open 'filename' in binary input mode (ios::in | ios::binary).
// Use seekg() to jump directly to recordIndex (offset = recordIndex * sizeof(Student)).
// Read the record into 'outStudent' using read() and reinterpret_cast<char*>.
bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    if (recordIndex < 0) return false;
    fstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }
    
    streamoff offset =
       static_cast<streamoff>(recordIndex) * sizeof(Student);
    
    inFile.seekg(offset, ios::beg);
    
    inFile.read(reinterpret_cast<char*>(&outStudent),
	sizeof(Student)
	);
	
	bool success = static_cast<bool>(inFile);

    // Hint: 
    // 1. streamoff offset = recordIndex * sizeof(Student);
    // 2. inFile.seekg(offset, ios::beg);
    // 3. inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));
    // 4. Return true if read succeeded, false otherwise.

    inFile.close();
    return success;
}


// ============================================================================
// CHAPTER 3: RECURSION
// ============================================================================

// TASK 7 [DEBUG]: Recursive Function to Compute Factorial of Total Students.
// BUG DESCRIPTION: Infinite recursion due to missing base case and non-decreasing recursive step.
int recursiveFactorial(int n) {
	if (n <= 1){
		return 1;
	}
    return n * recursiveFactorial(n-1); 
}

// TASK 8 [COMPLETE]: Recursive Linear Search for Student ID.
// Requirement: Recursively search 'list' from index 0 up to 'size - 1' for 'targetID'.
// Base Case 1: If current index reaches 'size', return -1 (Not Found).
// Base Case 2: If list[index].getID() == targetID, return index (Found).
// General Case: Recursively search next index (index + 1).
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
 if(currentIndex >= size){
 
    return -1;}
    
    if (list[currentIndex].getID() == targetID){
    	return currentIndex;
	}
	return recursiveSearchID(
	list, size, targetID, currentIndex +1);
}


// ============================================================================
// CHAPTER 4: ALGORITHM EFFICIENCY & STEP COUNTING
// ============================================================================

// TASK 9 [DEBUG]: Nested Loop Operation Counter.
// BUG DESCRIPTION: Loop termination variable error causing infinite loop during step counting.
void analyzeAlgorithmComplexity(int n) {
    int totalSteps = 0;
    cout << "\n--- Algorithm Efficiency Analysis (N = " << n << ") ---" << endl;

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

    int i = n;
    while (i > 0) {
        stepCount++;
        i /= 2;
    }

    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
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
    s1.setGPA(3.80f); // Task 2: valid GPA
    displayUsingPointer(&s1);
    s1.setGPA(4.50f); // Task 2: invalid GPA, retain 3.80
    displayUsingPointer(&s1);

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
