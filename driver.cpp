// driver.cpp
#include <iostream>
#include <limits>
#include "LinkedList.hpp"
#include "LinkedList.cpp"
#include "Student.hpp"
#include "Student.cpp"


// Function to clear input buffer
void clearInputBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    LinkedList studentList;
    int choice;

    do {
        std::cout << "\n--- Student Management System Menu ---" << std::endl;
        std::cout << "1. Insert a student" << std::endl;
        std::cout << "2. Delete a student by ID" << std::endl;
        std::cout << "3. Search for a student by ID" << std::endl;
        std::cout << "4. Display all students" << std::endl;
        std::cout << "5. Count the number of students" << std::endl;
        std::cout << "6. Add a course to a student" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1: {
                int id;
                std::string name;
                float gpa;
                std::cout << "Enter student ID: ";
                std::cin >> id;
                std::cout << "Enter student name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter student GPA: ";
                std::cin >> gpa;
                studentList.insert(Student(id, name, gpa));
                std::cout << "Student added successfully." << std::endl;
                break;
            }
            case 2: {
                int id;
                std::cout << "Enter ID of student to delete: ";
                std::cin >> id;
                if (studentList.deleteById(id)) {
                    std::cout << "Student with ID " << id << " deleted successfully." << std::endl;
                } else {
                    std::cout << "Student with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter ID of student to search: ";
                std::cin >> id;
                Student* student = studentList.searchById(id);
                if (student != nullptr) {
                    student->displayDetails();
                } else {
                    std::cout << "Student with ID " << id << " not found." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "--- All Students ---" << std::endl;
                studentList.displayAll();
                break;
            case 5:
                std::cout << "Total number of students: " << studentList.countStudents() << std::endl;
                break;
            case 6: {
                int studentId;
                std::string courseName, courseLocation;
                std::cout << "Enter ID of student to add a course to: ";
                std::cin >> studentId;
                Student* student = studentList.searchById(studentId);
                if (student != nullptr) {
                    std::cout << "Enter course name: ";
                    std::cin.ignore();
                    std::getline(std::cin, courseName);
                    std::cout << "Enter course location: ";
                    std::getline(std::cin, courseLocation);
                    student->addCourse(Course(courseName, courseLocation));
                    std::cout << "Course added successfully to student " << studentId << "." << std::endl;
                } else {
                    std::cout << "Student with ID " << studentId << " not found." << std::endl;
                }
                break;
            }
            case 7:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != 7);

    return 0;
}