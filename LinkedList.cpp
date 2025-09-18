
// LinkedList.cpp
#include "LinkedList.hpp"
#include <iostream>

// Destructor to free all allocated memory
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

// Insert a student at the end of the list
void LinkedList::insert(const Student& student) {
    Node* newNode = new Node(student);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Delete a student by ID
bool LinkedList::deleteById(int id) {
    if (head == nullptr) {
        return false;
    }

    if (head->student.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->student.id != id) {
        current = current->next;
    }

    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    return false;
}

// Search for a student by ID and display details
Student* LinkedList::searchById(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->student.id == id) {
            return &current->student;
        }
        current = current->next;
    }
    return nullptr;
}

// Display all students in the list
void LinkedList::displayAll() {
    if (head == nullptr) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        current->student.displayDetails();
        current = current->next;
    }
}

// Count the number of students
int LinkedList::countStudents() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}