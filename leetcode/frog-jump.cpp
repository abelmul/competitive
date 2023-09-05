#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int binarySearch(vector<int>& stones, int begin, int val)
    {
        int l = 0, r = stones.size() - 1;
        int m;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (stones[m] == val) {
                return m;
            }

            if (stones[m] < val) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return stones.size();
    }

    bool canCross(vector<int>& stones)
    {
        auto size = stones.size();
        unordered_map<long long, bool> memo;

        function<bool(int, int)> dp = [&](int l, int prevJump) {
            if (prevJump <= 0 || l < 0 || l >= size) {
                return false;
            }
            if (l == size - 1) {
                return true;
            }

            // because we can't use pair in unordered_map
            // use long long to make an index
            long long idx = (l << 8 | prevJump);

            if (memo.find(idx) == memo.end()) {
                memo[idx] = dp(binarySearch(stones, l, stones[l] + prevJump - 1), prevJump - 1) ||
                            dp(binarySearch(stones, l, stones[l] + prevJump), prevJump) ||
                            dp(binarySearch(stones, l, stones[l] + prevJump + 1), prevJump + 1);
            }

            return memo[idx];
        };

        return dp(binarySearch(stones, 0, 1), 1);
    }
};
