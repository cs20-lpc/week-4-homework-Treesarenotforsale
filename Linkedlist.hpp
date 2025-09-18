// LinkedList.hpp
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Student.hpp"

// Node structure for the linked list
struct Node {
    Student student;
    Node* next;

    Node(const Student& s) : student(s), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor and Destructor
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    // Operations
    void insert(const Student& student);
    bool deleteById(int id);
    Student* searchById(int id);
    void displayAll();
    int countStudents();
};

#endif // LINKEDLIST_HPP

// ---
