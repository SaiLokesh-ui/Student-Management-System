#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    string department;
    float cgpa;

public:
    Student(int rollNo, string name, string department, float cgpa) {
        this->rollNo = rollNo;
        this->name = name;
        this->department = department;
        this->cgpa = cgpa;
    }

    int getRollNo() const {
        return rollNo;
    }

    void display() const {
        cout << "\nRoll No: " << rollNo
             << "\nName: " << name
             << "\nDepartment: " << department
             << "\nCGPA: " << cgpa << "\n";
    }
};

void addStudent(vector<Student>& students) {
    int rollNo;
    string name, department;
    float cgpa;

    cout << "\nEnter roll number: ";
    cin >> rollNo;

    for (const Student& student : students) {
        if (student.getRollNo() == rollNo) {
            cout << "A student with this roll number already exists.\n";
            return;
        }
    }

    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter department: ";
    getline(cin, department);

    cout << "Enter CGPA: ";
    cin >> cgpa;

    if (cgpa < 0 || cgpa > 10) {
        cout << "Invalid CGPA. It must be between 0 and 10.\n";
        return;
    }

    students.emplace_back(rollNo, name, department, cgpa);
    cout << "Student added successfully.\n";
}

void viewStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo student records found.\n";
        return;
    }

    cout << "\n===== Student Records =====\n";
    for (const Student& student : students) {
        student.display();
    }
}

void searchStudent(const vector<Student>& students) {
    int rollNo;
    cout << "\nEnter roll number to search: ";
    cin >> rollNo;

    for (const Student& student : students) {
        if (student.getRollNo() == rollNo) {
            student.display();
            return;
        }
    }

    cout << "Student not found.\n";
}

void deleteStudent(vector<Student>& students) {
    int rollNo;
    cout << "\nEnter roll number to delete: ";
    cin >> rollNo;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getRollNo() == rollNo) {
            students.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }

    cout << "Student not found.\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: viewStudents(students); break;
            case 3: searchStudent(students); break;
            case 4: deleteStudent(students); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
