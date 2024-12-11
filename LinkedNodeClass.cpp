#include <iostream>
#include "LinkedNodeClass.h"

using namespace std;

// Programmer: Hao-Chun, Shih
// Date: 11/16/2024
// Purpose: Define LinkedNodeClass for getting value and setting node's pointer

LinkedNodeClass::LinkedNodeClass(LinkedNodeClass* inPrev, 
                                 const int &inVal, 
                                 LinkedNodeClass* inNext){
  prevNode = inPrev;
  nextNode = inNext;
  nodeVal = inVal;
}

int LinkedNodeClass::getValue() const{
  return nodeVal;
}

LinkedNodeClass* LinkedNodeClass::getNext() const{
  return nextNode;
}

LinkedNodeClass* LinkedNodeClass::getPrev() const{
  return prevNode;
}

void LinkedNodeClass::setNextPointerToNull(){
  nextNode = NULL;
}

void LinkedNodeClass::setPreviousPointerToNull(){
  prevNode = NULL;
}

void LinkedNodeClass::setBeforeAndAfterPointers(){
  if(this->prevNode == NULL){
    this->nextNode->prevNode = this;
  }

  else if(this->nextNode == NULL){
    this->prevNode->nextNode = this;
  }

  else{
    this->prevNode->nextNode = this;
    this->nextNode->prevNode = this;
  }
}
