#include <bits/stdc++.h>

using namespace std;

class MedianFinder
{
 private:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    size_t size() { return max_pq.size() + min_pq.size(); }

 public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (size() == 0 || num <= max_pq.top()) {
            max_pq.push(num);
        } else {
            min_pq.push(num);
        }

        // rebalance
        while (min_pq.size() + 1 < max_pq.size()) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        }

        while (max_pq.size() < min_pq.size()) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }

    double findMedian()
    {
        if (size() % 2 == 0) {
            return (double)(max_pq.top() + min_pq.top()) / 2;
        }

        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
