#include <bits/stdc++.h>

using namespace std;

class KthLargest
{
 private:
    int k;
    priority_queue<int, vector<int>, greater<int>> queue;

 public:
    KthLargest(int k, vector<int>& nums) : queue(nums.begin(), nums.end()) { this->k = k; }

    int add(int val)
    {
        queue.push(val);
        while (queue.size() > k) {
            queue.pop();
        }

        return queue.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
