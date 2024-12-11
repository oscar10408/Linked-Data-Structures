#include <iostream>
#include "SortedListClass.h"

using namespace std;
// Programmer: Hao-Chun, Shih
// Date: 11/16/2024
// Purpose: Define SortedListClass for insering, removing, printing
//          and getting element of specified index

const int MIN_INDEX = 0;

SortedListClass::SortedListClass(){
  head = NULL;
  tail = NULL;
}

SortedListClass::SortedListClass(const SortedListClass &rhs){
  head = NULL;
  tail = NULL;

  if(rhs.head == NULL){
    return;
  }

  LinkedNodeClass* copy = rhs.head;
  while(copy){
    this->insertValue(copy->getValue());
    copy = copy->getNext();
  }
}

SortedListClass::~SortedListClass(){
  clear();
}

SortedListClass& SortedListClass::operator=(const SortedListClass &rhs){
  this->clear();

  if(rhs.head == NULL){
    return *this;
  }

  LinkedNodeClass* copy = rhs.head;

  while(copy){
    this->insertValue(copy->getValue());
    copy = copy->getNext();
  }

  return *this;
}

void SortedListClass::clear(){
  LinkedNodeClass* deleteNode = NULL;
  
  while(head != NULL){
    deleteNode = head;
    head = head->getNext();
    delete deleteNode;
  }

  tail = NULL;
}


void SortedListClass::insertValue(const int &valToInsert){
  if(head == NULL){
    head = new LinkedNodeClass(NULL, valToInsert, NULL);
    tail = head;
  }

  else{
    LinkedNodeClass* currentNode = head;
    while(currentNode != NULL && currentNode->getValue() <= valToInsert){
      currentNode = currentNode->getNext();
    }
    
    if(currentNode == head){
      LinkedNodeClass* newNode;
      newNode = new LinkedNodeClass(NULL, valToInsert, head);
      newNode->setBeforeAndAfterPointers();
      head = newNode;
    }

    else if(currentNode == NULL){
      LinkedNodeClass* newNode;
      newNode = new LinkedNodeClass(tail, valToInsert, NULL);
      newNode->setBeforeAndAfterPointers();
      tail = newNode;
    }

    else{
      LinkedNodeClass* newNode;
      newNode = new LinkedNodeClass(currentNode->getPrev(),
                                    valToInsert, currentNode);
      newNode->setBeforeAndAfterPointers();
    }
  }
}

void SortedListClass::printForward() const{
  LinkedNodeClass* tempPtr = head;
  cout << "Forward List Contents Follow:" << endl;
  while(tempPtr != NULL){
    cout << "  " << tempPtr->getValue() << endl;
    tempPtr = tempPtr->getNext();
  }

  cout << "End Of List Contents" << endl;
}

void SortedListClass::printBackward() const{
  LinkedNodeClass* tempPtr = tail;
  cout << "Backward List Contents Follow:" << endl;

  while(tempPtr != NULL){
    cout << "  " << tempPtr->getValue() << endl;
    tempPtr = tempPtr->getPrev();
  }

  cout << "End Of List Contents" << endl;
}

bool SortedListClass::removeFront(int &theVal){
  if(head == NULL){
    return false;
  }
  
  else if(head == tail){
    theVal = head->getValue();
    delete head;
    head = NULL;
    tail = NULL;
    return true;
  }

  else{
    theVal = head->getValue();
    head = head->getNext();
    delete head->getPrev();
    head->setPreviousPointerToNull();
    return true;
  }
}

bool SortedListClass::removeLast(int &theVal){
  if(head == NULL){
    return false;
  }

  else if(head == tail){
    theVal = head->getValue();
    delete head;
    head = NULL;
    tail = NULL;
    return true;
  }

  else {
    theVal = tail->getValue();
    tail = tail->getPrev();
    delete tail->getNext();
    tail->setNextPointerToNull();
    return true;
  }

}

int SortedListClass::getNumElems() const{
  int numElements = 0;
  LinkedNodeClass* tempPtr = head;

  while(tempPtr != NULL){
    numElements++;
    tempPtr = tempPtr->getNext();
  }
  
  return numElements;
}

bool SortedListClass::getElemAtIndex(const int index, int &outVal) const{
  bool isSuccess = true;
  LinkedNodeClass* tempPtr = head;
  
  if(index < MIN_INDEX || index > getNumElems() || tempPtr == NULL){
    isSuccess = false;
  }

  else{
    for(int i = 0; i < index; i++){
      tempPtr = tempPtr->getNext();
    }
    outVal = tempPtr->getValue();
  }

  return isSuccess;
}

