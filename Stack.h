#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Stack Class using vectors
 */

class Stack{
protected:
    vector<int> stack;
public:
    Stack()= default;

    // Function declarations & definitions

    //POST: Return size of stack
    size_t size(){ return stack.size(); };

    //POST: True if stack empty, false if not empty
    bool empty(){ return stack.empty(); };

    //POST: Add num to top of stack
    void insert(int num){ stack.push_back(num); };

    //POST: Remove int at top of stack
    void remove(){ stack.pop_back(); };

    //POST: Return top of stack
    int top(){ return stack.back(); };

    //POST: Calculate and return average of integers in stack
    float avg(){
        float average = 0;
        float sum = 0;
        for (int i=0; i < size(); i++){
            sum+=float(stack[i]);
        }
        average = sum / float(size());
        return average;
    };

    //POST: Display contents of stack
    void print(){
        cout << "Index\t Integer\n";
        for (int i = (int(size()) - 1); i >= 0; i--){
            cout << i << "\t\t\t" << stack[i] << endl;
        }
    };
};