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

    bool setGPA(float newGpa) {
        if (newGpa >= 0.0f && newGpa <= 4.0f) {
            gpa = newGpa;
            return true;
        }
        cout << "Error: Invalid GPA. Must be between 0.0 and 4.0." << endl;
        return false;
    }
};



void displayUsingPointer(const Student* ptr) {
    if (ptr != nullptr) {
        ptr->printStudent(); 
    }
}



void printAllStudents(const Student list[], int size) {
    cout << "\n--- Student Roster ---" << endl;
    for (int i = 0; i < size; i++) { 
        list[i].printStudent();
    }
}



float calculateAverageGPA(const Student list[], int size) {
    if (size <= 0) return 0.0f;
    
    float totalGpa = 0.0f;
    for (int i = 0; i < size; i++) {
        totalGpa += list[i].getGPA();
    }
    
    return totalGpa / size;
}



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
    cout << "Successfully saved records to binary file: " << filename << endl;
}



bool readRecordAt(const char* filename, int recordIndex, Student& outStudent) {
    fstream inFile(filename, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening binary file for reading!" << endl;
        return false;
    }

    streamoff offset = static_cast<streamoff>(recordIndex) * sizeof(Student);
    inFile.seekg(offset, ios::beg);
    inFile.read(reinterpret_cast<char*>(&outStudent), sizeof(Student));

    bool success = inFile.good();
    inFile.close();
    return success;
}



int recursiveFactorial(int n) {
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1); 
}



int recursiveSearchID(const Student list[], int size, int targetID, int currentIndex = 0) {
    if (currentIndex >= size) return -1; 
    
    if (list[currentIndex].getID() == targetID) return currentIndex; 
    
    return recursiveSearchID(list, size, targetID, currentIndex + 1);
}



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



void analyzeLogarithmicEfficiency(int n) {
    int stepCount = 0;
    
    for (int i = n; i > 0; i /= 2) {
        stepCount++;
    }

    cout << "Logarithmic Step Count for N=" << n << ": " << stepCount << " steps." << endl;
}



int main() {
    cout << "=======================================================" << endl;
    cout << "  DSA Comprehensive Lab Exercise (Chapters 1 - 4)    " << endl;
    cout << "=======================================================" << endl;

    const int ROSTER_SIZE = 3;
    Student roster[ROSTER_SIZE] = {
        Student("Ahmad", 101, 3.75f),
        Student("Siti",  102, 3.90f),
        Student("Chong", 103, 3.50f)
    };

    cout << "\n--- Testing ADT & Pointers ---" << endl;
    Student s1("Nurul", 104, 3.20f);
    displayUsingPointer(&s1); 

    printAllStudents(roster, ROSTER_SIZE); 
    float avgGpa = calculateAverageGPA(roster, ROSTER_SIZE); 
    cout << "Calculated Average GPA: " << avgGpa << endl;

    const char* binaryFileName = "students.dat";
    saveToBinaryFile(binaryFileName, roster, ROSTER_SIZE); 

    Student retrievedStudent;
    if (readRecordAt(binaryFileName, 1, retrievedStudent)) { 
        cout << "Successfully retrieved record at index 1:" << endl;
        retrievedStudent.printStudent();
    }

    int fact = recursiveFactorial(4); 
    cout << "Factorial of 4: " << fact << endl;
    
    int foundIndex = recursiveSearchID(roster, ROSTER_SIZE, 102); 
    cout << "Recursive Search for ID 102 Found at Index: " << foundIndex << endl;

    analyzeAlgorithmComplexity(4); 
    analyzeLogarithmicEfficiency(16); 

    cout << "\n=======================================================" << endl;
    cout << "End of Testbench." << endl;
    return 0;
}