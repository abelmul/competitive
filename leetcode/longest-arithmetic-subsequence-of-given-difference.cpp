#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int longestSubsequence(vector<int>& arr, int difference)
    {
        int res = 0;
        unordered_map<int, int> m;

        for (auto a : arr) {
            if (m.find(a - difference) != m.end()) {
                m[a] = 1 + m[a - difference];
            } else {
                m[a] = 1;
            }
            res = max(res, m[a]);
        }

        return res;
    }
};
