#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<string> findRelativeRanks(vector<int>& score)
    {
        int n = score.size();

        vector<string> res(n);
        priority_queue<pair<int, int>> queue;
        pair<int, int> tmp;

        for (auto i = 0; i < n; ++i) {
            queue.push({score[i], i});
        }

        auto i = 0;
        if (i < n) {
            tmp = queue.top();
            queue.pop();
            res[tmp.second] = "Gold Medal";
            ++i;
        }
        if (i < n) {
            tmp = queue.top();
            queue.pop();
            res[tmp.second] = "Silver Medal";
            ++i;
        }
        if (i < n) {
            tmp = queue.top();
            queue.pop();
            res[tmp.second] = "Bronze Medal";
            ++i;
        }

        for (; i < n; ++i) {
            tmp = queue.top();
            queue.pop();
            res[tmp.second] = to_string(i + 1);
        }

        return res;
    }
};
