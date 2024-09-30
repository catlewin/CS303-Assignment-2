#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack{
protected:
    vector<int> stack;
public:
    Stack()= default;

    // Function declarations & definitions
    size_t size(){ return stack.size(); };
    bool empty(){ return stack.empty(); };
    void insert(int num){ stack.push_back(num); };
    void remove(){ stack.pop_back(); };
    int top(){ return stack.back(); };
    float avg(){
        float average = 0;
        float sum = 0;
        for (int i=0; i < size(); i++){
            sum+=float(stack[i]);
        }
        average = sum / float(size());
        return average;
    };
    void print(){
        cout << "Index\t Integer\n";
        for (int i = (int(size()) - 1); i >= 0; i--){
            cout << i << "\t\t\t" << stack[i] << endl;
        }
    };
};