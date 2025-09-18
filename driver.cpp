#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"
// TO DO:
// If you want to use the LinkedList code you wrote in Week 4 Mon Lab for creating list
// include LinkedList.hpp here and also add it both LinkedList.hpp and LinkedList.tpp to this repository.

using namespace std;

void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. View Student Details" << endl;
    cout << "4. Add Course to Student" << endl;
    cout << "5. View All Students" << endl;
    cout << "6. Exit" << endl;
    cout << "Select an option: ";
}

int main()
{
    LinkedList studentList;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add Student
                int id;
                string name;
                float gpa;

                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;

                Student newStudent(id, name, gpa);
                studentList.insert(newStudent);
                break;
            }
            case 2: {
                // Delete Student
                int id;
                cout << "Enter ID of student to delete: ";
                cin >> id;
                if (studentList.deleteById(id)) {
                    cout << "Student deleted." << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 3: {
                // View Student Details
                int id;
                cout << "Enter ID of student to view: ";
                cin >> id;
                Student* student = studentList.searchById(id);
                if (student) {
                    student->displayDetails();
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 4: {
                // Add Course to Student
                int id;
                string courseName, location;
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, courseName);
                cout << "Enter Course Location: ";
                getline(cin, location);

                Course newCourse(courseName, location);
                Student* student = studentList.searchById(id);
                if (student) {
                    student->addCourse(newCourse);
                    cout << "Course added to student." << endl;
                } else {
                    cout << "Student not found." << endl;
                }
                break;
            }
            case 5: {
                // View All Students
                studentList.displayAll();
                break;
            }
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}


        
