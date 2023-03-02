#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
            return sqrt(pow(a[0], 2) + pow(a[1], 2)) <
                   sqrt(pow(b[0], 2) + pow(b[1], 2));
        });

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
