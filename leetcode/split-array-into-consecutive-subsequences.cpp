#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isPossible(vector<int>& nums)
    {
        typedef priority_queue<int, vector<int>, greater<int>> min_queue;

        unordered_map<int, min_queue> pq;

        for (auto i : nums) {
            if (pq.find(i) == pq.end()) {
                pq[i] = min_queue();
            }
            if (pq.find(i - 1) != pq.end() && !pq.empty()) {
                pq[i].push(1 + pq[i - 1].top());
                pq[i - 1].pop();
                if (pq[i - 1].empty()) {
                    pq.erase(i - 1);
                }
            } else {
                pq[i].push(1);
            }
        }

        for (auto& [_, v] : pq) {
            if (!v.empty() && v.top() < 3) {
                return false;
            }
        }

        return true;
    }
};
