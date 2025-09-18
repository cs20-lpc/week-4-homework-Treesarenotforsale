// Student.hpp
#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector> // We must use this temporarily for the courses
#include "Course.hpp" 

class Student {
public:
    // Public members
    int id;
    std::string name;
    float gpa;
    std::vector<Course> courses; // Using vector for simplicity as the problem description focuses on the student linked list, not a course linked list.

    // Constructor
    Student(int studentId, const std::string& studentName, float studentGpa) 
        : id(studentId), name(studentName), gpa(studentGpa) {}

    // Methods
    void addCourse(const Course& course);
    void displayDetails() const;
};

#endif // STUDENT_HPP