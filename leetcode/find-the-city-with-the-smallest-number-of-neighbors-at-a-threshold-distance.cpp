#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<unsigned>> dist(n, vector<unsigned>(n, INT_MAX));

        int minNeighbours = INT_MAX;
        int res = INT_MAX;

        for (auto e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        for (auto i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }

        for (auto k = 0; k < n; ++k) {
            for (auto i = 0; i < n; ++i) {
                for (auto j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        for (auto i = 0; i < n; ++i) {
            auto withinThreshold = 0;
            for (auto j = 0; j < n; ++j) {
                if (i != j) {
                    withinThreshold += (dist[i][j] <= distanceThreshold);
                }
            }

            if (minNeighbours >= withinThreshold) {
                minNeighbours = withinThreshold;
                res = i;
            }
        }

        return res;
    }
};
