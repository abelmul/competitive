#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> cur;

        function<void(int, vector<int>&)> backtrack = [&](int i, vector<int>& cur) {
            if (cur.size() >= k) {
                res.push_back(cur);
                return;
            }

            if (i > n) {
                return;
            }

            // take i
            cur.push_back(i);
            backtrack(i + 1, cur);
            cur.pop_back();

            // don't take i
            backtrack(i + 1, cur);
        };

        backtrack(1, cur);

        return res;
    }
};
