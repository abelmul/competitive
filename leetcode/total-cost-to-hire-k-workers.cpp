#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        int size = costs.size();

        long long res = 0;

        int l, r;
        unordered_set<int> added;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (l = 0; l < min(candidates, size); ++l) {
            pq.push({costs[l], l});
        }

        for (r = size - 1; r >= max(0, size - candidates); --r) {
            pq.push({costs[r], r});
        }

        while (k--) {
            while (added.find(pq.top().second) != added.end()) {
                pq.pop();
            }

            auto t = pq.top();
            pq.pop();

            added.insert(t.second);

            res += t.first;

            if (l <= r) {
                if (t.second < l && l < size) {
                    pq.push({costs[l], l});
                    ++l;
                } else if (t.second > r && r >= 0) {
                    pq.push({costs[r], r});
                    --r;
                }
            }
        }

        return res;
    }
};
