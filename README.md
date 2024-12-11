# Linked-Data-Structures

## Overview
In this project, we will develop three common linked data structures: a **sorted doubly-linked list**, a **simple queue**, and a **simple stack**. This project will serve as the foundation for **Random Simulation**, which will fully utilize these data structures. Therefore, it is crucial to ensure the correctness and completeness of these implementations.

This project focuses on building the infrastructure (the data structures themselves) for later use in Project 5. You will need to write a main function to test your implementations. This function is for build purposes and testing but is not the focus of the project.

## Project Introduction

- **Doubly-Linked List**: Implement a sorted doubly-linked list.
- **Queue**: Implement a simple FIFO queue.
- **Stack**: Implement a simple LIFO stack.
- **Memory Management**: Ensure proper memory handling and avoid memory leaks using tools like `valgrind`.
- **Makefile**: A valid `Makefile` for compiling the project.

## Classes Implemented

### 1. `LinkedNodeClass`

This class will represent a node in a doubly-linked structure, storing the value and pointers to the next and previous nodes.

```cpp
class LinkedNodeClass {
private:
    LinkedNodeClass *prevNode; // Points to the previous node.
    int nodeVal;               // Value of the node.
    LinkedNodeClass *nextNode; // Points to the next node.
public:
    LinkedNodeClass(LinkedNodeClass *inPrev, const int &inVal, LinkedNodeClass *inNext);
    int getValue() const;
    LinkedNodeClass* getNext() const;
    LinkedNodeClass* getPrev() const;
    void setNextPointerToNull();
    void setPreviousPointerToNull();
    void setBeforeAndAfterPointers();
};
```

### 2. `SortedListClass`
```cpp
class SortedListClass {
private:
    LinkedNodeClass *head; // Points to the first node.
    LinkedNodeClass *tail; // Points to the last node.
public:
    SortedListClass();
    SortedListClass(const SortedListClass &rhs);
    ~SortedListClass();
    SortedListClass& operator=(const SortedListClass &rhs);
    void clear();
    void insertValue(const int &valToInsert);
    void printForward() const;
    void printBackward() const;
    bool removeFront(int &theVal);
    bool removeLast(int &theVal);
    int getNumElems() const;
    bool getElemAtIndex(const int index, int &outVal) const;
};
```

### 3. `FIFOQueueClass`
```cpp
class FIFOQueueClass {
private:
    LinkedNodeClass *head;
    LinkedNodeClass *tail;
public:
    FIFOQueueClass();
    ~FIFOQueueClass();
    void enqueue(int value);
    bool dequeue(int &value);
    bool isEmpty() const;
    int getSize() const;
};
```

### 4. `LIFOStackClass`
```cpp
class LIFOStackClass {
private:
    LinkedNodeClass *top;
public:
    LIFOStackClass();
    ~LIFOStackClass();
    void push(int value);
    bool pop(int &value);
    bool isEmpty() const;
    int getSize() const;
};
```
