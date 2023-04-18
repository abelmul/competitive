#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> cur;

        auto length = candidates.size();

        sort(candidates.begin(), candidates.end());

        function<void(int, vector<int>&, int)> backtrack = [&](int l, vector<int>& cur, int sum) {
            if (sum == target) {
                res.push_back(cur);
                return;
            } else if (sum > target) {
                return;
            }

            for (auto i = l; i < length; ++i) {
                if (i <= l || candidates[i - 1] != candidates[i]) {
                    cur.push_back(candidates[i]);
                    backtrack(i + 1, cur, sum + candidates[i]);
                    cur.pop_back();
                }
            }
        };

        backtrack(0, cur, 0);

        return res;
    }
};
