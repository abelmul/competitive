#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int distributeCookies(vector<int>& cookies, int k)
    {
        auto length = cookies.size();
        vector<int> cur(k);

        sort(cookies.begin(), cookies.end());

        function<int(int, vector<int>&)> backtrack = [&](int l,
                                                         vector<int>& cur) {
            if (l >= length) {
                return *max_element(cur.begin(), cur.end());
            }

            int res = INT_MAX;

            for (auto i = 0; i < k; ++i) {
                // give te current cookies to child i
                if (cur[i] + cookies[l] > res)
                    continue;
                if (i > 0 && cur[i] == cur[i - 1])
                    continue;

                cur[i] += cookies[l];
                res = min(res, backtrack(l + 1, cur));
                cur[i] -= cookies[l];
            }

            return res;
        };

        return backtrack(0, cur);
    }
};
