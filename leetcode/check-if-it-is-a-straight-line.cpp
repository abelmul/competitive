#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        pair<int, int> u,
            v = {coordinates[1][1] - coordinates[0][1], coordinates[1][0] - coordinates[0][0]};

        for (auto i = 2; i < coordinates.size(); ++i) {
            u = {coordinates[i][1] - coordinates[0][1], coordinates[i][0] - coordinates[0][0]};

            if (v.first * u.second != v.second * u.first)
                return false;
        }

        return true;
    }
};
