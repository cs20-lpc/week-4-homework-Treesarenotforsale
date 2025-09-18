// TODO:  Course class definitins go here.
#ifndef COURSE_HPP
#define COURSE_HPP

#include <string>

class Course {
private:
    std::string courseName;
    std::string location; // e.g., "Room 101"

public:
    // Constructor
    Course(const std::string& name,const std::string& loc)
        : courseName(name), location(loc) {}

    // Getter for courseName
    std::string getCourseName() const { return courseName; }


    // Getter for location
    std::string getLocation() const { return location; }
};

#endif // COURSE_HPP