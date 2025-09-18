// TODO:  Student class methods implementation here.
// Student.cpp
#include "Student.hpp"
#include <iostream>

// Add a course to the student's list
void Student::addCourse(const Course& course) {
    courses.push_back(course);
}

// Display student details
void Student::displayDetails() const {
    std::cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << std::endl;
    std::cout << "Courses Enrolled:" << std::endl;
    for (const auto& course : courses) {
        std::cout << "  - " << course.getCourseName() << " at " << course.getLocation() << std::endl;
    }
}