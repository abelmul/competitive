#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        auto n = nums1.size(), m = nums2.size();

        std::priority_queue<pair<int, pair<int, int>>> queue;
        pair<int, pair<int, int>> tmp;

        vector<vector<int>> res;

        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (queue.size() < k) {
                    queue.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
                } else {
                    tmp = queue.top();

                    if (nums1[i] + nums2[j] >= tmp.first) {
                        break;
                    }

                    queue.push({nums1[i] + nums2[j], {nums1[i], nums2[j]}});

                    while (queue.size() > k) {
                        queue.pop();
                    }
                }
            }
        }

        while (!queue.empty()) {
            tmp = queue.top();
            queue.pop();

            res.push_back({tmp.second.first, tmp.second.second});
        }

        return res;
    }
};
