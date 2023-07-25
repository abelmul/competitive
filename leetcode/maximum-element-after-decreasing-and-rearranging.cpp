#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
    {
        auto n = arr.size();

        sort(arr.begin(), arr.end());

        if (arr[0] != 1) {
            arr[0] = 1;
        }
        for (auto i = 1; i < n; ++i) {
            if (arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        return arr.back();
    }
};
