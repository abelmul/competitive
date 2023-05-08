#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isBeautifulArrangement(int i, int val)
    {
        int j = i + 1;
        return val % j == 0 || j % val == 0;
    }

    int countArrangement(int n)
    {
        vector<int> cur(n);
        int res = 0;

        // init
        iota(cur.begin(), cur.end(), 1);

        function<void(int, vector<int>&)> backtrack = [&](int l, vector<int>& cur) {
            if (l >= n) {
                ++res;
                return;
            }

            for (int i = l; i < n; ++i) {
                if (isBeautifulArrangement(l, cur[i])) {
                    swap(cur[i], cur[l]);
                    backtrack(l + 1, cur);
                    swap(cur[i], cur[l]);
                }
            }
        };

        backtrack(0, cur);

        return res;
    }
};
