// NAME: Cat Lewin
// CS303 Assignment 2

/*
 * .cpp file for Linked List not included due to Template Class not connecting .h & .cpp files
 */

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

using namespace std;


int main() {
  //PART ONE -- Template Single Linked List Instantiations (int & str)
  cout << "PART ONE:\n\n";
  //INTEGER linked list instantiation
  Linked<int> myList;
  for (int i = 0; i < 10; i++){ // load LL with integers
    myList.push_back(i);
  }

  cout << "Original Int List\n";
  myList.print();

  cout << "\nModifications:\n"
          "  .pop_back()\n"
          "  .push_front(100)\n"
          "  .insert(4, 44)\n"
          "  .remove(50)\n"
          "  .pop_front();\n"
          "  .insert(100, 555);\n\n";
  myList.pop_back();
  myList.push_front(100);
  myList.insert(4, 44);
  myList.remove(50);
  myList.pop_front();
  myList.insert(100, 555);


  cout << "Modified Int List\n";
  myList.print();

  cout << endl << endl;

  //STRING linked list instantiation
  Linked<string> strList;
  strList.push_back("abc");
  strList.push_back("123");
  strList.push_back("KansasCity");
  strList.push_back("456");
  strList.push_back("DesMoines");

  cout << "Original Str List\n";
  strList.print();

  cout << endl << endl;
  cout << "\nModifications:\n"
          "  .pop_front()\n"
          "  .push_front(\"Begin\")\n"
          "  .insert(2, \"fun\")\n"
          "  .pop_back();\n"
          "  .insert(100, \"515\")\n"
          "  .remove(3)\n\n";

  strList.pop_front();
  strList.push_front("Begin");
  strList.insert(2, "fun");
  strList.pop_back();
  strList.insert(100, "End");
  strList.remove(3);



  cout << "Modified Str List\n";
  strList.print();

  //PART TWO -- Stack class instantiation
  cout << "\n\nPart Two:\n\n";
  Stack myStack;
  for (int i = 0; i < 10; i++){
      myStack.insert(i);
  }
  cout << "Original Stack\n";
  myStack.print();
    cout << "\nModifications:\n"
            "  .remove()\n"
            "  .insert(4)\n";

  myStack.remove();
  myStack.insert(4);


  cout << "\n\nModified Stack\n";
  myStack.print();

  cout << "\nAverage of current stack: " << myStack.avg();

}