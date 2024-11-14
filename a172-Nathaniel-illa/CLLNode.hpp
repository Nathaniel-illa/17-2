#ifndef CLLNODE_HPP
#define CLLNODE_HPP
// ********************************************************
// Code your program here
// All files for this project are 
// CLL.hpp, CLLNode.hpp, main.cpp, tests.cpp
// In this file, you need to define the class CLL
//! CLASS NAME: CLL
// ********************************************************
// Define your class definition and implementation here
// No need to use cpp file
// ******************************************************** 


// CLLNode class template for nodes in the Circular Linked List
template <class T>
class CLLNode {
private:
    T data;                 // The data stored in the node
    CLLNode<T>* next;       // Pointer to the next node in the list

public:
    // Default constructor
    CLLNode() : data(), next(nullptr) {}

    // Parameterized constructor
    CLLNode(T data, CLLNode<T>* next = nullptr) : data(data), next(next) {}

    // Returns the data stored in the node
    T getData() const { return data; }

    // Returns the pointer to the next node
    CLLNode<T>* getNext() const { return next; }

    // Sets the data of the node
    void setData(T data) { this->data = data; }

    // Sets the next pointer of the node
    void setNext(CLLNode<T>* next) { this->next = next; }
};

#endif