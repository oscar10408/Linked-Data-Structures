#include <iostream>
#include "SortedListClass.h"
#include "LIFOStackClass.h"
#include "FIFOQueueClass.h"

using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else 

int main()
{
  //This is just a placeholder main function - it does exceptionally
  //little actual testing, so you'll want to add your own tests here.
  //Feel free to leave your tests in the version of this file you
  //submit, but we will not be running your main function, so the
  //output, etc., of your main doesn't need to match anything from
  //a sample output, etc.
  SortedListClass testList;
  
  cout << "Testing insertion and printout function" << endl;
  testList.printForward();
  testList.printBackward();

  cout << "Inserting 20, 40, 100, 60" << endl;  
  testList.insertValue(20);
  testList.insertValue(40);
  testList.insertValue(100);
  testList.insertValue(60);

  testList.printForward();
  testList.printBackward();

  cout << "Testing copy constructor" << endl;
  SortedListClass copy(testList);

  cout << "Copied list:" << endl;
  copy.printForward();
  cout << "Original list:" << endl;
  testList.printForward();

  cout << "Inserting 25 into Copied list" << endl;
  copy.insertValue(25);

  cout << "Clear the Original list" << endl;
  testList.clear();

  cout << "Copied list:" << endl;
  copy.printForward();
  cout << "Original list:" << endl;
  testList.printForward();  

  cout << "Testing getElemAtIndex function" << endl;
  int retrievedElement;
  cout << "There is " << copy.getNumElems() << " nodes in the Copy." << endl;
  if (copy.getElemAtIndex(2, retrievedElement))
  {
    cout << "The index 2 node in the Copy has value " << retrievedElement << endl;
  }
  if (!copy.getElemAtIndex(-9, retrievedElement))
  {
    cout << "Invalid index" << endl;
  }
  if (!copy.getElemAtIndex(100, retrievedElement))
  {
    cout << "Invalid index" << endl;
  }

  cout << "Testing removeFront function" << endl;
  int frontNodeCopy;
  while (copy.removeFront(frontNodeCopy))
  {
    cout << "Remove the front node of the Copy" << endl;
    cout << frontNodeCopy << " is removed" << endl;
  }
  if (!copy.removeFront(frontNodeCopy))
  {
    cout << "The list has became empty!" << endl;
  }

  cout << "The Original:" << endl;
  testList.printForward();
  testList.printBackward();
  cout << "The Copy:" << endl;
  copy.printForward();
  copy.printBackward();


  cout << "Inserting 5,15,35,25 into original list" << endl;
  testList.insertValue(5);
  testList.insertValue(15);
  testList.insertValue(35);
  testList.insertValue(25);

  cout << "Testing removeLast function" << endl;
  int lastNodeCopy;
  
  while (testList.removeLast(lastNodeCopy))
  {
    cout << "Remove the last node of the Original" << endl;
    cout << lastNodeCopy << " is removed" << endl;
  }
  if (!testList.removeLast(lastNodeCopy))
  {
    cout << "No more node to remove!" << endl;
  }

  cout << "The Original:" << endl;
  testList.printForward();
  testList.printBackward();
  cout << "The Copy:" << endl;
  copy.printForward();
  copy.printBackward();


  cout << "Here is a FIFO queue Queue" << endl;
  FIFOQueueClass queue1;
  queue1.enqueue(5);
  queue1.enqueue(10);
  queue1.enqueue(1);
  queue1.enqueue(100);
  queue1.enqueue(10);
  queue1.enqueue(20);

  cout << "Printing Queue: ";
  queue1.print();
  cout << endl;

  int dequeuedInt;
  while (queue1.dequeue(dequeuedInt))
  {
    cout << "Dequeuing" << endl;
    cout << dequeuedInt << " is dequeued." << endl;
  }
  if (!queue1.dequeue(dequeuedInt))
  {
    cout << "Fail to dequeue: Empty Queue!" << endl;
  }
  cout << "Printing Queue:" << endl;
  queue1.print();
  cout << endl;


  cout << "Here is a LIFO stack Stack" << endl;
  LIFOStackClass stack1;
  stack1.push(8);
  stack1.push(81);
  stack1.push(23);
  stack1.push(24);
  stack1.push(8);
  stack1.push(100);

  cout << "Printing Stack: ";
  stack1.print();
  cout << endl;

  int poppedInt;
  while (stack1.pop(poppedInt))
  {
    cout << "Popping" << endl;
    cout << poppedInt << " is popped." << endl;
  }
  if (!stack1.pop(poppedInt))
  {
    cout << "Fail to pop: Empty Stack!" << endl;
  }

  cout << "Printing Stack: ";
  stack1.print();
  cout << endl;

  return 0;
}

#endif