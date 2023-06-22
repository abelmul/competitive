#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k)
    {
        auto n = arr.size();
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto i = 0; i < n; ++i) {
            for (auto j = n - 1; j > i; --j) {
                pq.push({static_cast<double>(arr[i]) / arr[j], {arr[i], arr[j]}});

                while (pq.size() > k) {
                    pq.pop();
                }
            }
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};
