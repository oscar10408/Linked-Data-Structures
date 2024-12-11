#include <iostream>
#include "LIFOStackClass.h"

using namespace std;

// Programmer: Hao-Chun, Shih
// Date: 11/16/2024
// Purpose: Define LIFOStackClass for constructing a queue using
//          LinkedNodeClass and SortedListClass

LIFOStackClass::LIFOStackClass(){
  head = NULL;
  tail = NULL;
}

LIFOStackClass::~LIFOStackClass(){
  clear();
}

void LIFOStackClass::push(const int &newItem){
  LinkedNodeClass* newNode = NULL;
  
  if(head == NULL){
    head = new LinkedNodeClass(NULL, newItem, NULL);
    tail = head;
  }

  else{
    newNode = new LinkedNodeClass(tail, newItem, NULL);
    newNode->setBeforeAndAfterPointers();
    tail = newNode;
  }
}

bool LIFOStackClass::pop(int &outItem){
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
    LinkedNodeClass* tempNode = tail;
    outItem = tail->getValue();
    tail = tail->getPrev();
    delete tempNode;
    tail->setNextPointerToNull();
    return true;
  }
}

void LIFOStackClass::print() const{
  LinkedNodeClass* tempPtr = head;

  while(tempPtr != NULL){
    cout << tempPtr->getValue() << " ";
    tempPtr = tempPtr->getNext();
  }

  cout << endl;
}

int LIFOStackClass::getNumElems() const{
  int numElements = 0;
  LinkedNodeClass* tempPtr = head;

  while(tempPtr != NULL){
    numElements++;
    tempPtr = tempPtr->getNext();
  }
  
  return numElements;
}

void LIFOStackClass::clear(){
  LinkedNodeClass* deleteNode = head;
  
  while(head != NULL){
    deleteNode = head;
    head = head->getNext();
    delete deleteNode;
  }
  
  tail = NULL;
}