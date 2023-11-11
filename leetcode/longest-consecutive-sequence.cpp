#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int longestConsecutive(vector<int>& nums)
    {
        auto n = nums.size();

        unordered_map<int, int> pos;
        vector<int> root(n), rank(n, 1);

        iota(root.begin(), root.end(), 0);

        function<int(int)> find = [&](int i) {
            if (i != root[i]) {
                root[i] = find(root[i]);
            }
            return root[i];
        };

        auto join = [&](int x, int y) {
            if (y < n) {
                x = find(x);
                y = find(y);

                if (x != y) {
                    if (rank[y] > rank[x]) {
                        swap(x, y);
                    }

                    root[y] = x;
                    rank[x] += rank[y];
                }
            }
        };

        for (auto i = 0; i < n; ++i) {
            if (pos.find(nums[i]) == pos.end()) {
                pos[nums[i]] = i;
                if (pos.find(nums[i] - 1) != pos.end()) {
                    join(i, pos[nums[i] - 1]);
                }
                if (pos.find(nums[i] + 1) != pos.end()) {
                    join(i, pos[nums[i] + 1]);
                }
            }
        }

        return reduce(rank.begin(), rank.end(), 0, [](auto v, auto mx) { return max(mx, v); });
    }
};
