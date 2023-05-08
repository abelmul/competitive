#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool isBoomerang(vector<vector<int>>& points)
    {
        float area = ((points[1][0] - points[0][0]) * (points[2][1] - points[1][1])) -
                     ((points[2][0] - points[1][0]) * (points[1][1] - points[0][1]));

        return area / 2 != 0;
    }
};
