#pragma once
#include <iostream>
#include <string>
using namespace std;

// Node struct used to define nodes in the linked list
template<class T>
struct Node {
    T data;
    Node *nextPtr;
    explicit Node(T d, Node* nextP = nullptr); //Node constructor
};

template<class T>
Node<T>::Node(T d, Node *nextP) : data(d), nextPtr(nextP) {} //Node constructor

// Linked class declaration
template<class T>
class Linked {
protected:
    Node<T> *headPtr;
    Node<T> *tailPtr;
    int num_items{};
public:
    Linked(){ //default constructor
        headPtr = nullptr;
        tailPtr = nullptr;
    };
    ~Linked(){ //destructor
        Node<T>* tempPtr = headPtr;
        while (tempPtr != nullptr) {
            Node<T>* next = tempPtr->nextPtr;
            delete tempPtr;
            tempPtr = next;
        }
        headPtr = nullptr;
    };

    //function declarations & definitions

    //POST: New node created at front of linked list
    void push_front(T d){
        auto* newN = new Node<T>(d, headPtr);
        headPtr = newN;
        num_items++;
    };

    //POST: New node created at back of linked list
    void push_back(T d){
        auto* newN = new Node<T>(d);
        if (tailPtr == nullptr && headPtr == nullptr){
            headPtr = newN;
        }
        else{
            tailPtr->nextPtr = newN;
        }
        tailPtr = newN;
        num_items++;
    };

    //POST: Remove front node
    void pop_front(){
        if (headPtr == nullptr){ //empty list
            return;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
        }
        else{
            Node<T>* delN = headPtr;
            headPtr = headPtr->nextPtr;
            delete delN;
            num_items--;
        }
    };

    //POST: Remove back node
    void pop_back(){
        if (headPtr == nullptr && tailPtr == nullptr){ //empty list
            return;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
        }
        else{
            Node<T>* currentP = headPtr;
            while (currentP->nextPtr->nextPtr != nullptr){ //continue until 1 before tailPtr
                currentP = currentP->nextPtr;
            }
            Node<T>* delN = tailPtr;
            tailPtr = currentP;
            tailPtr->nextPtr = nullptr;
            delete delN;
            num_items--;
        }
    };

    //POST: Return front pointer
    Node<T>* front(){
        return headPtr;
    };

    //POST: Return tail pointer
    Node<T>* back(){
        return tailPtr;
    };

    //POST: Return true/false based on if linked list is empty
    bool empty(){
        if (headPtr == nullptr && tailPtr == nullptr){
            return true;
        }
        else{
            return false;
        }
    };

    //POST: Insert new node at index
    void insert(size_t index, T d){
        if (empty()){ //empty list
            auto* newN = new Node<T>(d);
            headPtr = newN;
            tailPtr = newN;
            num_items++;
        }
        else if (index >= num_items){  //at end of list
            push_back(d);
        }
        else{ //inserting in middle
            int count = 0;
            Node<T>* current = headPtr;
            while (count != index - 1){ //move through list to find node before insert position
                current = current->nextPtr;
                count++;
            }
            //update pointers
            auto* newN = new Node<T>(d, current->nextPtr);
            current->nextPtr = newN;
            num_items++;
        }
    };

    //POST: returns true if node at index successfully removed, false if unsuccessful
    bool remove(size_t index){
        if (index >= num_items){ //index out of bounds or empty list
            return false;
        }
        else if (headPtr->nextPtr == nullptr){ //only 1 node
            delete headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            num_items--;
            return true;
        }
        else{ //more than 1 node
            int count = 0;
            Node<T>* current = headPtr;
            while (count != index - 1){ //move through list to find node before delete position
                current = current->nextPtr;
                count++;
            }
            //update pointers
            Node<T>* delN = current->nextPtr;
            current->nextPtr = current->nextPtr->nextPtr;
            delete delN;
            num_items--;
            return true;
        }
    };

    //POST: returns index of value d in linked list
    size_t find(T d){
        if (empty()){
            return 0;
        }
        else{
            int count = 0;
            Node<T>* current = headPtr;
            while (current != nullptr){
                if (current->data == d){
                    return count;
                }
                current = current->nextPtr;
                count++;
            }
            return num_items;
        }
    };

    //POST: displays linked list
    void print(){
        int count = 0;
        Node<T>* tempN = front();
        cout << "Index\t Data\n";
        while (tempN != nullptr){
            cout << count << "\t\t\t" << tempN->data << endl;
            count++;
            tempN = tempN->nextPtr;
        }
    };
};