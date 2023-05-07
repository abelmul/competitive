#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        vector<vector<int>> res;
        res.push_back(vector<int>());
        res.push_back(vector<int>());

        for (auto n : s1) {
            if (s2.find(n) == s2.end()) {
                res[0].push_back(n);
            }
        }
        for (auto n : s2) {
            if (s1.find(n) == s1.end()) {
                res[1].push_back(n);
            }
        }

        return res;
    }
};
