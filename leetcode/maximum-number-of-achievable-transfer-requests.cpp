#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maximumRequests(int n, vector<vector<int>>& requests)
    {
        int r_size = requests.size();
        int res = 0;
        vector<int> cur(n);

        auto or_acc = [](int r, int c) { return r | c; };

        function<void(int, int, vector<int>&)> backtrack = [&](int i, int elements,
                                                               vector<int>& cur) {
            // accumulate current
            if (i == r_size) {
                if (accumulate(cur.begin(), cur.end(), 0, or_acc) == 0) {
                    res = max(res, elements);
                }

                return;
            }

            // take i
            --cur[requests[i][0]];
            ++cur[requests[i][1]];
            backtrack(i + 1, elements + 1, cur);

            ++cur[requests[i][0]];
            --cur[requests[i][1]];

            // don't take i
            backtrack(i + 1, elements, cur);
        };

        backtrack(0, 0, cur);

        return res;
    }
};
