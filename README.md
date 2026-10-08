# Student Management System

A beginner-friendly C++ console application for managing student records.

## Features
- Add a student
- View all students
- Search by roll number
- Delete a student
- Prevent duplicate roll numbers
- Validate CGPA from 0 to 10

## Concepts Used
- C++ classes and objects
- Encapsulation
- Constructors
- `vector`
- Functions
- Loops and conditionals
- Input validation
- Basic CRUD operations

## How to Run

```bash
g++ main.cpp -o student_management
./student_management
```

On Windows:

```bash
g++ main.cpp -o student_management.exe
student_management.exe
```

## Project Structure

```text
Student-Management-System/
├── main.cpp
└── README.md
```

Student data is stored in memory while the program is running; this version does not use a database or permanent file storage.
