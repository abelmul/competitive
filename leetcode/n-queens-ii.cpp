#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    inline bool canBeAttacked(int i, int j, const vector<pair<int, int>>& queens)
    {
        for (auto pos : queens) {
            if (pos.first == i || pos.second == j || abs(pos.first - i) == abs(pos.second - j)) {
                return true;
            }
        }

        return false;
    }
    int totalNQueens(int n)
    {
        vector<pair<int, int>> queens;
        int res = 0;

        function<void(vector<pair<int, int>>&)> backtrack = [&](vector<pair<int, int>>& queens) {
            if (queens.size() == n) {
                ++res;
                return;
            }

            auto r = queens.size();

            for (auto i = 0; i < n; ++i) {
                if (!canBeAttacked(r, i, queens)) {
                    queens.push_back(make_pair(r, i));
                    backtrack(queens);
                    queens.pop_back();
                }
            }
        };

        backtrack(queens);

        return res;
    }
};
