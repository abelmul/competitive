#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int minStoneSum(vector<int>& piles, int k)
    {
        int res = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());

        while (k--) {
            res -= pq.top() / 2;
            pq.push(pq.top() - pq.top() / 2);
            pq.pop();
        }

        return res;
    }
};
