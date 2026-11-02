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
        // TODO (TASK 2): Write the validation and assignment code here.
        if (newGpa < 0 || newGpa > 4)
		{
			cout << "Please enter an acceptable value";
			return false; // Replace this placeholder	
		}
		
		gpa = newGpa;
        return true;
        
    }
};

// ============================================================================
// TASK 1 [DEBUG]: POINTER TO OBJECT FUNCTION
// ============================================================================
// Goal: Print student info using a pointer to an object.
// BUG DESCRIPTION: The function below uses dot operator '.' on an object pointer.
void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        // --- BUG HERE (TASK 1) ---
         ptr -> printStudent(); // UNCOMMENT AND FIX THIS LINE 
    }
}


// ============================================================================
// TASK 3 [DEBUG] & TASK 4 [COMPLETE]: ARRAY OF OBJECTS OPERATIONS
// ============================================================================

// TASK 3 [DEBUG]: Function intended to display all students in an array.
// BUG DESCRIPTION: Loop index off-by-one bug causes array out-of-bounds access.
void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    // --- BUG HERE (TASK 3) ---
    for (int i = 0; i <= size - 1; i++) { 
        list[i].printStudent();
    }
}

// TASK 4 [COMPLETE]: Calculate Average GPA of Student Array.
// Requirement: Iterate through list[] up to 'size' elements and return the average GPA.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    float totalGpa = 0.0f;

    // TODO (TASK 4): Write loop here to sum GPAs and calculate average.
    for (int i = 0; i <= size - 1; i++) { 
        totalGpa += list[i].getGPA(); 
    }

    return totalGpa/size; // Replace with calculated average
}


// ============================================================================
// CHAPTER 2B: ADVANCED BINARY FILE OPERATIONS
// ============================================================================

// TASK 5 [DEBUG]: Save Array of Objects to Binary File.
// BUG DESCRIPTION: Missing binary flag and wrong stream output operator used instead of write().
void saveToBinaryFile(const char* filename, const Student list[], int size) {
    // --- BUG HERE (TASK 5) ---
    fstream outFile(filename, ios::out|ios::binary); 
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        
         outFile.write(reinterpret_cast<const char *>(&list[i]), sizeof(list[i])); 
        
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

    // TODO (TASK 6): Complete the seekg() positioning and read() execution.
    // Hint: 
    // 1. streamoff offset = recordIndex * sizeof(Student);
    // 2. inFile.seekg(offset, ios::beg);
    // 3. inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));
    // 4. Return true if read succeeded, false otherwise.
    
    streamoff offset = recordIndex * sizeof(Student);
    inFile.seekg(offset, ios::beg);
    inFile.read(reinterpret_cast<char *>(&outStudent), sizeof(Student));
    
    bool succeeded = !inFile.fail();

    inFile.close();
    return succeeded;
}


// ============================================================================
// CHAPTER 3: RECURSION
// ============================================================================

// TASK 7 [DEBUG]: Recursive Function to Compute Factorial of Total Students.
// BUG DESCRIPTION: Infinite recursion due to missing base case and non-decreasing recursive step.
int recursiveFactorial(int n) {
    // --- BUG HERE (TASK 7) ---
    if (n <= 1)
    	return 1; 
    else
    	return n * recursiveFactorial(n - 1); 
}

// TASK 8 [COMPLETE]: Recursive Linear Search for Student ID.
// Requirement: Recursively search 'list' from index 0 up to 'size - 1' for 'targetID'.
// Base Case 1: If current index reaches 'size', return -1 (Not Found).
// Base Case 2: If list[index].getID() == targetID, return index (Found).
// General Case: Recursively search next index (index + 1).
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    // TODO (TASK 8): Write base cases and recursive step here.
	if (currentIndex >= size)
		return -1;
	else if (list[currentIndex].getID() == targetID)
		return currentIndex;
	else
		return recursiveSearchID(list, size, targetID, currentIndex + 1);
 	 // Placeholder
}


// ============================================================================
// CHAPTER 4: ALGORITHM EFFICIENCY & STEP COUNTING
// ============================================================================

// TASK 9 [DEBUG]: Nested Loop Operation Counter.
// BUG DESCRIPTION: Loop termination variable error causing infinite loop during step counting.
void analyzeAlgorithmComplexity(int n) {
    int totalSteps = 0;
    cout << "\n--- Algorithm Efficiency Analysis (N = " << n << ") ---" << endl;

    // --- BUG HERE (TASK 9) ---
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n;) {
            totalSteps++;
            j++; 
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

    // TODO (TASK 10): Implement while loop or for loop where i halves each step (i /= 2) until i <= 0.
    // Inside loop: stepCount++;
	for (int i = n; i > 0; i /= 2)
	{
		stepCount++;
	}
	
    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
    // TODO (TASK 10 Comment): State the Big O complexity class of this algorithm below:
    // Complexity: O(log N)
    // Total steps executed: 5 steps
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
    cout << "RecursiveFactorial output when inputing 4: " << fact << endl;
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102); // Task 8
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    // Test Task 9 & 10
    analyzeAlgorithmComplexity(4); // Task 9
    analyzeLogarithmicEfficiency(16); // Task 10

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    
    
    return 0;
}
