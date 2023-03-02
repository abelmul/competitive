#include <bits/stdc++.h>
using namespace std;

class MinStack
{
 private:
    std::vector<int> data;
    int min;

 public:
    MinStack()
    {
        data = std::vector<int>();
        min = std::numeric_limits<int>::max();
    }

    void push(int val)
    {
        data.push_back(val);

        if (min > val) {
            min = val;
        }
    }

    void pop()
    {
        int top = this->top();

        data.pop_back();

        if (top == min) {
            min = std::numeric_limits<int>::max();
            if (data.size() > 0) {
                for (int d : data) {
                    if (min > d)
                        min = d;
                }
            }
        }
    }

    int top() { return data.back(); }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
