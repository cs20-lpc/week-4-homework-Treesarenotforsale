#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"
#include "LinkedList.hpp"

using namespace std;

int main()
{
  // Create a linked list to store Student objects
    LinkedList<Student> studentList;
    int choice;
    float gpa;
    int id;
    string name;
    string courseName, courseLocation;
    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Add Course to Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore(); // To ignore the newline character left in the buffer
                getline(cin, name);
                cout << "Enter Student GPA: ";
                cin >> gpa;
                studentList.append(Student(id, name, gpa));
                cout << "Student added successfully.\n";
                break;
            case 2:
                // Implement delete functionality
                cout << "Delete functionality not implemented yet.\n";
                break;
            case 3:
                // Implement search functionality
                cout << "Search functionality not implemented yet.\n";
                break;
            case 4:
                if (studentList.isEmpty()) {
                    cout << "No students in the list.\n";
                } else {
                    for (int i = 0; i < studentList.getLength(); ++i) {
                        Student s = studentList.getElement(i);
                        s.displayDetails();
                    }
                }
                break;
            case 5:
                cout << "Enter Student ID to add course: ";
                cin >> id;
                {
                    bool found = false;
                    for (int i = 0; i < studentList.getLength(); ++i) {
                        Student& s = studentList.getElement(i);
                        if (s.id == id) {
                            found = true;
                            cout << "Enter Course Name: ";
                            cin.ignore(); // To ignore the newline character left in the buffer
                            getline(cin, courseName);
                            cout << "Enter Course Location: ";
                            getline(cin, courseLocation);
                            s.addCourse(Course(courseName, courseLocation));
                            cout << "Course added successfully to student ID " << id << ".\n";
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Student with ID " << id << " not found.\n";
                    }
                }
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
