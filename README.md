# Tutoring Center Management

A program developed in C to manage information about students receiving tutoring at a tutoring center.

## Features

- Input student data.
- Save data to a binary file.
- Read and list registered students.
- Sort students by the number of hours attended.
- Search for students by course unit.
- Remove a student by name.
- Calculate the amount to be paid by undergraduate students.

## Stored Information

Each student is characterized by:

- Name.
- Qualification level: CTeSP, Bachelor's, or Master's.
- Course unit.
- Hourly rate.
- Number of hours attended.

## Application Menu

```text
Input Student Information[1]
Save Student Information to File[2]
Read from File and List All Students[3]
Sort by Number of Hours Attended and List[4]
Search and Display Students by Course Unit[5]
Remove a Student by Name[6]
Calculate Amount Payable by Undergraduate Students[7]
Exit
```

## Technologies Used

- C language.
- Structures and enumerated types.
- Arrays of structures.
- Binary files.
- Functions and modular programming. ## Files

Student data is saved in the binary file:

```text
explicandos.dat
```

## How to run

Compile the program using a C compiler:

```bash
gcc *.c -o centro-explicacoes
```

Run:

```bash
./centro-explicacoes
```

On Windows:

```bash
centro-explicacoes.exe
```

## Authors

- Gustavo Silva 
  

