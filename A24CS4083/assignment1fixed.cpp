#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
private:
    char name[30];
    int studentID;
    float gpa;

public:
    Student() {
        strcpy(name, "Undefined");
        studentID = 0;
        gpa = 0.0f;
    }

    Student(const char* n, int id, float g) {
        strncpy(name, n, 29);
        name[29] = '\0';
        studentID = id;
        gpa = g;
    }

    int getID() const { return studentID; }
    float getGPA() const { return gpa; }
    const char* getName() const { return name; }

    void printStudent() const {
        cout << "ID: " << studentID << " | Name: " << name << " | GPA: " << gpa << endl;
    }

    // TASK 2: Update GPA only when it is within the valid range.
    bool setGPA(float newGpa) {
        if (newGpa >= 0.0f && newGpa <= 4.0f) {
            gpa = newGpa;
            return true;
        }
        cout << "Error: GPA must be between 0.0 and 4.0." << endl;
        return false;
    }
};

// TASK 1: Use the arrow operator to access a member through a pointer.
void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        ptr->printStudent();
    }
}

// TASK 3: Stop before the array size to avoid out-of-bounds access.
void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    for (int i = 0; i < size; i++) {
        list[i].printStudent();
    }
}

// TASK 4: Calculate the average GPA.
float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;

    float totalGpa = 0.0f;
    for (int i = 0; i < size; i++) {
        totalGpa += list[i].getGPA();
    }
    return totalGpa / size;
}

// TASK 5: Write each Student record in binary format.
void saveToBinaryFile(const char* filename, const Student list[], int size) {
    ofstream outFile(filename, ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    for (int i = 0; i < size; i++) {
        outFile.write(reinterpret_cast<const char*>(&list[i]), sizeof(Student));
    }

    if (!outFile) {
        cout << "Error writing records to binary file!" << endl;
        return;
    }

    outFile.close();
    cout << "Successfully saved records to binary file: " << filename << endl;
}

// TASK 6: Read one record directly using its index.
bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    if (recordIndex < 0) return false;

    ifstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }

    streamoff offset = static_cast<streamoff>(recordIndex) * sizeof(Student);
    inFile.seekg(offset, ios::beg);
    if (!inFile) return false;

    inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));
    return static_cast<bool>(inFile);
}

// TASK 7: Factorial with a terminating base case.
int recursiveFactorial(int n) {
    if (n < 0) return -1; // Negative values do not have a factorial.
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1);
}

// TASK 8: Recursive linear search.
int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    if (currentIndex >= size) return -1;
    if (list[currentIndex].getID() == targetID) return currentIndex;
    return recursiveSearchID(list, size, targetID, currentIndex + 1);
}

// TASK 9: Count operations in a nested loop.
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

// TASK 10: Count iterations of a loop that halves i each time.
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

int main() {
    cout << "=======================================================" << endl;
    cout << "  DSA Comprehensive Lab Exercise (Chapters 1 - 4)    " << endl;
    cout << "=======================================================" << endl;

    const int ROSTER_SIZE = 3;
    Student roster[ROSTER_SIZE] = {
        Student("Ahmad", 101, 3.75f),
        Student("Siti", 102, 3.90f),
        Student("Chong", 103, 3.50f)
    };

    cout << "\n--- Testing ADT & Pointers ---" << endl;
    Student s1("Nurul", 104, 3.20f);
    displayUsingPointer(&s1);

    cout << "\n--- Testing GPA Update ---" << endl;
    if (s1.setGPA(3.60f)) {
        cout << "GPA updated successfully: " << s1.getGPA() << endl;
    }

    printAllStudents(roster, ROSTER_SIZE);
    float avgGpa = calculateAverageGPA(roster, ROSTER_SIZE);
    cout << "Calculated Average GPA: " << avgGpa << endl;

    const char* binaryFileName = "students.dat";
    saveToBinaryFile(binaryFileName, roster, ROSTER_SIZE);

    Student retrievedStudent;
    if (readRecordAt(binaryFileName, 1, retrievedStudent)) {
        cout << "Successfully retrieved record at index 1:" << endl;
        retrievedStudent.printStudent();
    } else {
        cout << "Could not retrieve record at index 1." << endl;
    }

    cout << "\n--- Testing Recursion ---" << endl;
    cout << "Factorial of 4: " << recursiveFactorial(4) << endl;
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102);
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    analyzeAlgorithmComplexity(4);
    analyzeLogarithmicEfficiency(16);

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    return 0;
}
