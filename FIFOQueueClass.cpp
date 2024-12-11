#include <iostream>
#include "FIFOQueueClass.h"

using namespace std;

// Programmer: Hao-Chun, Shih
// Date: 11/16/2024
// Purpose: Define FIFOQueueClass for constructing a queue using
//          LinkedNodeClass and SortedListClass

FIFOQueueClass::FIFOQueueClass(){
  head = NULL;
  tail = NULL;
}

FIFOQueueClass::~FIFOQueueClass(){
  clear();
}

void FIFOQueueClass::enqueue(const int &newItem){
  
  LinkedNodeClass* newNode = NULL;
  
  if(head == NULL){
    head = new LinkedNodeClass(NULL, newItem, NULL);
    tail = head;
  }

  else{
    newNode = new LinkedNodeClass(tail, newItem, NULL);
    tail = newNode;
    newNode->setBeforeAndAfterPointers();
  }
}

bool FIFOQueueClass::dequeue(int &outItem){
  if(head == NULL){
    return false;
  }

  else if(head == tail){
    outItem = head->getValue();
    delete head;
    head = NULL;
    tail = NULL;
    return true;
  }

  else{
    LinkedNodeClass* tempNode = head;
    outItem = head->getValue();
    head = head->getNext();
    delete tempNode;
    head->setPreviousPointerToNull();
    return true;
  }
}

void FIFOQueueClass::print() const{
  LinkedNodeClass* tempPtr = head;

  while(tempPtr != NULL){
    cout << tempPtr->getValue() << " " ;
    tempPtr = tempPtr->getNext();
  }

  cout << endl;
}

int FIFOQueueClass::getNumElems() const{
  int numElements = 0;
  LinkedNodeClass* tempPtr = head;

  while(tempPtr != NULL){
    numElements++;
    tempPtr = tempPtr->getNext();
  }
  
  return numElements;
}

void FIFOQueueClass::clear(){
  
  LinkedNodeClass* deleteNode = NULL;

  while(head != NULL){
    deleteNode = deleteNode->getNext();
    delete deleteNode;
  }
  
  tail = NULL;
}