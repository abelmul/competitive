#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findMaxLength(vector<int>& nums)
    {
        auto size = nums.size();
        int res = 0;

        unordered_map<int, int> map;
        int counter = 0;

        map[0] = 0;

        for (auto i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                --counter;
            } else {
                ++counter;
            }

            if (map.find(counter) != map.end()) {
                res = max(res, i - map[counter] + 1);
            } else {
                map[counter] = i + 1;
            }
        }

        return res;
    }
};
