#include <bits/stdc++.h>

using namespace std;

class MyQueue {
private:
    vector<int> push_stack,pop_stack;
    
    void move_to_pop_stack() {
        if(pop_stack.empty()) {
            while(!push_stack.empty()){
                pop_stack.push_back(push_stack.back());
                push_stack.pop_back();
            }
        }
    }
public:
    MyQueue() {
        push_stack = vector<int>();
        pop_stack = vector<int>();
    }
    
    void push(int x) {
        push_stack.push_back(x);
    }
    
    int pop() {
        move_to_pop_stack();
        
        int top = pop_stack.back();
        pop_stack.pop_back();
        
        return top;
    }
    
    int peek() {
        move_to_pop_stack();
        
        return pop_stack.back();
    }
    
    bool empty() {
        return push_stack.empty() && pop_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
