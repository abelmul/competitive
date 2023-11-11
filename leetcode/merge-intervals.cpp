#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> res;

        auto size = intervals.size();

        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            if (res.empty() || res.back()[1] < interval[0]) {
                res.push_back(interval);
            } else {
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }

        return res;
    }
};
