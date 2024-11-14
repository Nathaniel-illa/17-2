#ifndef CLL_HPP
#define CLL_HPP

#include "CLLNode.hpp"
// ********************************************************
// Code your program here
// All files for this project are 
//* CLL.hpp, CLLNode.hpp, main.cpp, tests.cpp
// In this file, you need to define the class CLLNode
//! CLASS NAME: CLLNode
// ********************************************************
// Define your class definition and implementation here
// No need to use cpp file
// ******************************************************** 

// CLL class template for a Circular Linked List
template <class T>
class CLL {
private:
    CLLNode<T>* tail;  // Pointer to the tail node (last node in the list)

public:
    // Constructor to initialize an empty list
    CLL() : tail(nullptr) {}

    // Destructor to delete all nodes in the list
    ~CLL() {
        if (tail != nullptr) {
            CLLNode<T>* current = tail->getNext();  // Start from head node
            CLLNode<T>* nextNode;
            while (current != tail) {
                nextNode = current->getNext();
                delete current;
                current = nextNode;
            }
            delete tail;   // Delete the tail node
            tail = nullptr; // Set tail to nullptr to mark the list as empty
        }
    }

    // Checks if the list is empty (returns 1 if empty, 0 otherwise)
    int isEmpty() const {
        return (tail == nullptr) ? 1 : 0;
    }

    // Returns the pointer to the tail node
    CLLNode<T>* getTail() const {
        return tail;
    }

    // Adds a new node with the given value at the end of the list
    void addtoTail(T el) {
        CLLNode<T>* newNode = new CLLNode<T>(el);
        if (isEmpty()) {
            tail = newNode;
            tail->setNext(tail);  // Point to itself, making it circular
        } else {
            newNode->setNext(tail->getNext());  // Point new node to head
            tail->setNext(newNode);             // Update tail's next to new node
            tail = newNode;                     // Move tail to new node
        }
    }

    // Deletes the first occurrence of a node with the given value
    void deleteNode(T el) {
        if (isEmpty()) return; // No nodes to delete

        CLLNode<T>* current = tail->getNext();  // Start from head node
        CLLNode<T>* previous = tail;
        do {
            if (current->getData() == el) {
                if (current == tail) { // Deleting the tail node
                    if (tail->getNext() == tail) { // Only one node
                        delete tail;
                        tail = nullptr;
                    } else {
                        previous->setNext(current->getNext());
                        tail = previous;
                        delete current;
                    }
                } else { // Deleting any other node
                    previous->setNext(current->getNext());
                    delete current;
                }
                return;
            }
            previous = current;
            current = current->getNext();
        } while (current != tail->getNext());
    }

    // Returns the total number of nodes in the circular linked list
    int getNumNodes() const {
        if (isEmpty()) return 0;

        int count = 1;
        CLLNode<T>* current = tail->getNext(); // Start from head node
        while (current != tail) {
            current = current->getNext();
            count++;
        }
        return count;
    }
};

#endif