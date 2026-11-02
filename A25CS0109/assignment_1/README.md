## ASSIGNMENT 1

<img width="350" alt="logo-FC-website-header" src="https://github.com/user-attachments/assets/d7ac3e9e-8322-47db-bf9a-658c928347c3" />

***Student Details:***
| Information    | Student Details |
| -------- | ------- |
| **Student Name**  | `MUHAMMAD NAWFAL BIN MOHD SHAIFUDDIN`    |
| **Matric No.** | `A25CS0109`     |
| **Section**    | `SECTION 03`    |
| **Lecturer Name**    | `DR. MUHAMMAD KHATIBSYARBINI`    |
| **Final Submission Date**    | `BEFORE WEEK 4 MONDAY CLASS`    |

---

### 📝 Summary of Tasks Completed
*   **Task 1 & 3 (Debug):** Fixed object pointer access using `->` and fixed array out-of-bounds by changing `<=` to `<`.
*   **Task 2 & 4 (Complete):** Implemented `setGPA()` with 0.0-4.0 validation and completed `calculateAverageGPA()`.
*   **Task 5 & 6 (Binary Files):** Added `ios::binary` for file writing and implemented `seekg()`/`read()` for random-access reading.
*   **Task 7 & 8 (Recursion):** Fixed infinite recursion in Factorial by adding a base case, and completed the recursive linear search for Student IDs.
*   **Task 9 & 10 (Big O):** Fixed an infinite nested loop and implemented a logarithmic halving loop (Complexity: **O(log N)**).

---

### 💻 Program Output

```
=======================================================
  DSA Comprehensive Lab Exercise (Chapters 1 - 4)    
=======================================================

--- Testing ADT & Pointers ---
ID: 104 | Name: Nurul | GPA: 3.2

--- Student Roster ---
ID: 101 | Name: Ahmad | GPA: 3.75
ID: 102 | Name: Siti | GPA: 3.9
ID: 103 | Name: Chong | GPA: 3.5
Calculated Average GPA: 3.71667
Successfully saved records to binary file: students.dat
Successfully retrieved record at index 1:
ID: 102 | Name: Siti | GPA: 3.9
Factorial of 4: 24
Recursive Search for ID 102 Found at Index: 1

--- Algorithm Efficiency Analysis (N = 4) ---
Total Basic Operations Executed: 16 steps.
Theoretical Complexity: O(N^2)
Logarithmic Step Count for N=16: 5 steps.

=======================================================
End of Testbench.
```

Note: There are also `students.dat` file that were created.
