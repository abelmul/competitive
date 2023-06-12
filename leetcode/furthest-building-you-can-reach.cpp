#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        auto n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;

        int res = n - 1;

        for (auto i = 1; i < n; ++i) {
            auto height_diff = heights[i] - heights[i - 1];
            if (height_diff < 0) {
                continue;
            }

            pq.push(height_diff);

            if (ladders < pq.size()) {
                bricks -= pq.top();
                pq.pop();
            }

            if (bricks < 0) {
                res = i - 1;
                break;
            }
        }

        return res;
    }
};
