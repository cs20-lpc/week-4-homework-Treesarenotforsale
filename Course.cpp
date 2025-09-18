// TODO:  Course class methods implementation here.
// Course.cpp
#include "Course.hpp"

// Constructor implementation
Course::Course(const std::string& name, const std::string& loc) 
    : courseName(name), location(loc) {}

// Getter implementations
std::string Course::getCourseName() const {
    return courseName;
}

std::string Course::getLocation() const {
    return location;
}