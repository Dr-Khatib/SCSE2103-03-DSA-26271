# Assignment 1 - Comprehensive DSA Debug & Code Completion

- Full name: SUN RUOYU
- Matric number: A25CS4023
- Course: SCSE2103, Section 03, Session 2026/2027/1

## Completed work

Completed Tasks 1-10: object pointers, GPA validation, array bounds and averaging, binary file writing and random-access reading, recursive factorial and ID search, and quadratic/logarithmic step counting. The provided Task 9 already incremented j in its body; the update is now in the for-loop header.

## Compile and run

```sh
g++ -std=c++11 -Wall -Wextra -Wpedantic dsa_assignment1.cpp -o dsa_assignment1
./dsa_assignment1
```

On Windows, run `dsa_assignment1.exe`. The program creates `students.dat` in the working directory.

## Validation

Compiled and ran with GCC 13.1.0 and Dev-C++ GCC 4.9.2. Additional local checks passed for GPA boundaries and invalid values, empty arrays, missing/truncated files, record bounds, factorial base cases, unsuccessful searches, and zero/negative loop inputs.

Expected main results: average GPA 3.71667; record 1 is Siti (102, GPA 3.9); factorial(4) = 24; ID 102 at index 1; missing ID returns -1; quadratic loop at N=4 counts 16 steps; halving loop at N=16 counts 5 steps.
