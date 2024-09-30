// NAME: Cat Lewin
// CS303 Assignment 2

#include <iostream>
#include "LinkedList.h"

using namespace std;


int main() {
  cout << "PART ONE:\n\n";
  Linked<int> myList;
  for (int i = 0; i < 10; i++){ // load LL with integers
    myList.push_back(i);
  }

  cout << "Original Int List\n";
  cout << "Index\t Data\n";
  int count = 0;
  Node<int>* tempN = myList.front();
  while (tempN != nullptr){
      cout << count << "\t\t\t" << tempN->data << endl;
      count++;
      tempN = tempN->nextPtr;
  }

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
  cout << "Index\t Data\n";
  count = 0;
  tempN = myList.front();
  while (tempN != nullptr){
    cout << count << "\t\t\t" << tempN->data << endl;
    count++;
    tempN = tempN->nextPtr;
  }

  cout << endl << endl;

  Linked<string> strList;
  strList.push_back("abc");
  strList.push_back("123");
  strList.push_back("KansasCity");
  strList.push_back("456");
  strList.push_back("DesMoines");

  cout << "Original Str List\n";
  cout << "Index\t Data\n";
  count = 0;
  Node<string>* tempS = strList.front();
  while (tempS != nullptr){
      cout << count << "\t\t\t" << tempS->data << endl;
      count++;
      tempS = tempS->nextPtr;
  }

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
  cout << "Index\t Data\n";
  count = 0;
  tempS = strList.front();
  while (tempS != nullptr){
      cout << count << "\t\t\t" << tempS->data << endl;
      count++;
      tempS = tempS->nextPtr;
  }

  cout << "Part Two:\n\n";
}