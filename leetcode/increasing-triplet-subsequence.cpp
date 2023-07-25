#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool increasingTriplet(vector<int>& nums)
    {
        int low = INT_MAX, high = INT_MAX;

        for (auto n : nums) {
            if (n <= low) {
                low = n;
            } else if (n <= high) {
                high = n;
            } else {
                return true;
            }
        }

        return false;
    }
};
