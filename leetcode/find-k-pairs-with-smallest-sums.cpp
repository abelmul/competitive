#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        vector<vector<int>> res;

        auto n = nums1.size(), m = nums2.size();
        std::function<bool(const pair<int, int>&, const pair<int, int>&)> compare =
            [&nums1, &nums2](const pair<int, int>& a, const pair<int, int>& b) {
                return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
            };

        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> queue(
            compare);
        pair<int, int> tmp;

        queue.push({0, 0});

        while (k-- && queue.size()) {
            tmp = queue.top();
            queue.pop();

            res.push_back({nums1[tmp.first], nums2[tmp.second]});

            if (tmp.first + 1 < n) {
                queue.push({tmp.first + 1, tmp.second});
            }

            if (tmp.first == 0 && tmp.second + 1 < m) {
                queue.push({tmp.first, tmp.second + 1});
            }
        }

        return res;
    }
};
