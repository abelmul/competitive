#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int peakIndexInMountainArray(vector<int>& arr)
    {
        auto l = 0;
        auto r = arr.size() - 1;

        while (l < r) {
            auto m = l + (r - l) / 2;

            if (arr[m] < arr[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }

        return l;
    }
};
