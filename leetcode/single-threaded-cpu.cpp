#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<int> getOrder(vector<vector<int>>& tasks)
    {
        auto size = tasks.size();

        function<bool(int, int)> compare = [&](int lhs, int rhs) {
            return tasks[lhs][0] > tasks[rhs][0];
        };

        function<bool(int, int)> enqued_compare = [&](int lhs, int rhs) {
            return tasks[lhs][1] > tasks[rhs][1] || (tasks[lhs][1] == tasks[rhs][1] && lhs > rhs);
        };
        priority_queue<int, vector<int>, decltype(compare)> unfinished(compare);
        priority_queue<int, vector<int>, decltype(enqued_compare)> queued(enqued_compare);

        long long time = 0;
        vector<int> res;

        for (auto i = 0; i < size; ++i) {
            unfinished.push(i);
        }

        while (!unfinished.empty() || !queued.empty()) {
            while (!unfinished.empty() && time >= tasks[unfinished.top()][0]) {
                queued.push(unfinished.top());
                unfinished.pop();
            }

            if (!queued.empty()) {
                res.push_back(queued.top());
                time += tasks[queued.top()][1];
                queued.pop();
            } else {
                time = tasks[unfinished.top()][0];
            }
        }

        return res;
    }
};
