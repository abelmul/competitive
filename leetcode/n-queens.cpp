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

    inline vector<string> constructBoard(const vector<pair<int, int>>& queens)
    {
        vector<string> ans;
        string s;

        ans.resize(queens.size());
        s.resize(queens.size());

        for (auto pos : queens) {
            fill(s.begin(), s.end(), '.');
            s[pos.first] = 'Q';
            ans[pos.second] = s;
        }

        return ans;
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<pair<int, int>> queens;
        vector<vector<string>> res;

        function<void(vector<pair<int, int>>&)> backtrack = [&](vector<pair<int, int>>& queens) {
            if (queens.size() == n) {
                res.push_back(constructBoard(queens));
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
