#include <bits/stdc++.h>

using namespace std;

class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> pq;

 public:
    SeatManager(int n)
    {
        pq = priority_queue<int, vector<int>, greater<int>>();

        for (auto i = 1; i < n + 1; ++i) {
            pq.push(i);
        }
    }

    int reserve()
    {
        auto t = pq.top();
        pq.pop();

        return t;
    }

    void unreserve(int seatNumber) { pq.push(seatNumber); }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
