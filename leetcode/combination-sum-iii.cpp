#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> cur;

        function<void(int, vector<int>&, int)> backtrack = [&](int l, vector<int>& cur, int sum) {
            if (cur.size() == k) {
                if (sum == n)
                    res.push_back(cur);
                return;
            }

            for (auto i = l; i < 10; ++i) {
                cur.push_back(i);
                backtrack(i + 1, cur, sum + i);
                cur.pop_back();
            }
        };

        backtrack(1, cur, 0);

        return res;
    }
};
