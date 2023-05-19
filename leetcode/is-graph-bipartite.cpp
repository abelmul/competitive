#include <bits/stdc++.h>

using namespace std;

class Solution
{
 public:
    bool colorDfs(const vector<vector<int>>& graph, int i, vector<int>& colors, int prev_color)
    {
        if (colors[i] != -1)
            return colors[i] == !prev_color;

        colors[i] = !prev_color;

        for (auto c : graph[i]) {
            if (!colorDfs(graph, c, colors, !prev_color)) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph)
    {
        auto size = graph.size();

        vector<int> colors(size);
        fill(colors.begin(), colors.end(), -1);

        for (auto i = 0; i < size; ++i) {
            if (colors[i] == -1 && !colorDfs(graph, i, colors, 0))
                return false;
        }

        return true;
    }
};
