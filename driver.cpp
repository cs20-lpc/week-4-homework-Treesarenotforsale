#include <iostream>
#include <string>
#include "LinkedList.hpp"

using namespace std;

// Function to clear input buffer without using <limits>
void clearInputBuffer() {
    cin.ignore(256, '\n'); 
}

int main() {
    LinkedList studentList;
    int choice;

    do {
        cout << "\n--- Student Management System Menu ---" << endl;
        cout << "1. Insert a student" << endl;
        cout << "2. Delete a student by ID" << endl;
        cout << "3. Search for a student by ID" << endl;
        cout << "4. Display all students" << endl;
        cout << "5. Count the number of students" << endl;
        cout << "6. Add a course to a student" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                int id;
                string name;
                float gpa;
                cout << "Enter student ID: ";
                cin >> id;
                cout << "Enter student name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter student GPA: ";
                cin >> gpa;
                studentList.insert(Student(id, name, gpa));
                cout << "Student added successfully." << endl;
                break;
            }
            case 2: {
                int id;
                cout << "Enter ID of student to delete: ";
                cin >> id;
                if (studentList.deleteById(id)) {
                    cout << "Student with ID " << id << " deleted successfully." << endl;
                } else {
                    cout << "Student with ID " << id << " not found." << endl;
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter ID of student to search: ";
                cin >> id;
                Student* student = studentList.searchById(id);
                if (student != nullptr) {
                    student->displayDetails();
                } else {
                    cout << "Student with ID " << id << " not found." << endl;
                }
                break;
            }
            case 4:
                cout << "--- All Students ---" << endl;
                studentList.displayAll();
                break;
            case 5:
                cout << "Total number of students: " << studentList.countStudents() << endl;
                break;
            case 6: {
                int studentId;
                string courseName, courseLocation;
                cout << "Enter ID of student to add a course to: ";
                cin >> studentId;
                Student* student = studentList.searchById(studentId);
                if (student != nullptr) {
                    cout << "Enter course name: ";
                    cin.ignore();
                    getline(cin, courseName);
                    cout << "Enter course location: ";
                    getline(cin, courseLocation);
                    student->addCourse(Course(courseName, courseLocation));
                    cout << "Course added successfully to student " << studentId << "." << endl;
                } else {
                    cout << "Student with ID " << studentId << " not found." << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 7);

    return 0;
}