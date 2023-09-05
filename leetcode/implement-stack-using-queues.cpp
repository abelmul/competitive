#include <bits/stdc++.h>

using namespace std;

class MyStack
{
 private:
    queue<int> q;

 public:
    MyStack() : q() {}

    void push(int x)
    {
        q.push(x);
        int size = q.size();
        for (auto _ = 0; _ < size - 1; ++_) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int res = q.front();
        q.pop();

        return res;
    }

    int top() { return q.front(); }

    bool empty() { return q.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
